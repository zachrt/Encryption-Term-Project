#include "FileHandler.h"

string FileHandler::readFile(const string& path) {
    ifstream file(path, ios::binary);

    if (!file.is_open()) {
        cout << "Error: could not open file: " << path << "\n";
        return "";
    }

    // Converts the file content into a string
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    file.close();

    // Returns string
    return content;
}

void FileHandler::writeFile(const string& path, const string& data) {
    ofstream file(path, ios::binary);

    if (!file.is_open()) {
        cout << "Error: could not write file: " << path << "\n";
        return;
    }

    file.write(data.c_str(), data.size());
    file.close();
}

string FileHandler::pickFile() {
    string dir;
    cout << "Enter directory to browse (or press Enter for current): ";
    getline(cin, dir);

    if (dir.empty()) dir = ".";

    if (!filesystem::exists(dir)) {
        cout << "Directory not found: " << dir << "\n";
        return "";
    }

    vector<string> files;
    for (auto& entry : filesystem::directory_iterator(dir))
        if (entry.is_regular_file())
            files.push_back(entry.path().string());

    if (files.empty()) {
        cout << "No files found in: " << dir << "\n";
        return "";
    }

    sort(files.begin(), files.end());

    cout << "\nFiles in " << dir << ":\n";
    cout << "---------------------------\n";
    for (int i = 0; i < (int)files.size(); i++)
        cout << i + 1 << ". " << filesystem::path(files[i]).filename().string() << "\n";
    cout << "---------------------------\n";
    cout << "Pick a number (or 0 to type a path manually): ";

    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 0) {
        string path;
        cout << "Enter full file path: ";
        getline(cin, path);
        return path;
    }

    if (choice < 1 || choice > (int)files.size()) {
        cout << "Invalid choice.\n";
        return "";
    }

    return files[choice - 1];
}

string FileHandler::pickOutputPath() {
    string dir;
    cout << "Enter directory for output (or press Enter for current): ";
    getline(cin, dir);

    if (dir.empty()) dir = ".";

    cout << "\nExisting files in " << dir << ":\n";
    cout << "---------------------------\n";
    for (auto& entry : filesystem::directory_iterator(dir))
        if (entry.is_regular_file())
            cout << "  " << entry.path().filename().string() << "\n";
    cout << "---------------------------\n";
    cout << "Enter output filename: ";

    string name;
    getline(cin, name);

    if (name.size() < 5 || name.substr(name.size() - 5) != ".huff")
    name += ".huff";

    return dir + "/" + name;
}