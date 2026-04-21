#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>
#include "Node.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include "FileHandler.h"
#include "Encryptor.h"

using namespace std;

unordered_map<char, int> getFrequencies(const string& input) {
    unordered_map<char, int> map;
    for (char c : input)
        map[c]++;
    return map;
}

void compressFile() {
    cout << "\n-- SELECT INPUT FILE --\n";
    string inPath = FileHandler::pickFile();
    if (inPath.empty()) return;

    cout << "\n-- SELECT OUTPUT FILE --\n";
    string outPath = FileHandler::pickOutputPath();
    if (outPath.empty()) return;

    string input = FileHandler::readFile(inPath);
    if (input.empty()) {
        cout << "Error: file is empty or could not be read.\n";
        return;
    }

    // --- Start timer ---
    auto start = chrono::high_resolution_clock::now();

    unordered_map<char, int> freqMap = getFrequencies(input);
    PriorityQueue pq;
    for (auto& x : freqMap)
        pq.push(new Node(x.first, x.second));

    HuffmanTree tree;
    tree.build(pq);
    string compressed = tree.compress(input);

    // --- Stop timer ---
    auto end = chrono::high_resolution_clock::now();

    FileHandler::writeFile(outPath, compressed);

    auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    auto us = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "\nDone!\n";
    cout << "Original size:   " << input.size()      << " bytes\n";
    cout << "Compressed size: " << compressed.size() << " bytes\n";
    cout << "Space saved:     "
         << (100 - (compressed.size() * 100 / input.size()))
         << "%\n";
    cout << "Saved to:        " << outPath << "\n";

    if (ms > 0)
        cout << "Time taken:      " << ms << " ms\n";
    else
        cout << "Time taken:      " << us << " us\n";
}

void decompressFile() {
    cout << "\n-- SELECT INPUT FILE --\n";
    string inPath = FileHandler::pickFile();
    if (inPath.empty()) return;

    cout << "\n-- SELECT OUTPUT FILE --\n";
    string outPath = FileHandler::pickOutputPath();
    if (outPath.empty()) return;

    string compressed = FileHandler::readFile(inPath);
    if (compressed.empty()) {
        cout << "Error: file is empty or could not be read.\n";
        return;
    }

    // --- Start timer ---
    auto start = chrono::high_resolution_clock::now();

    HuffmanTree tree;
    string result = tree.decompress(compressed);

    // --- Stop timer ---
    auto end = chrono::high_resolution_clock::now();

    FileHandler::writeFile(outPath, result);

    auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    auto us = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "\nDone!\n";
    cout << "Compressed size:   " << compressed.size() << " bytes\n";
    cout << "Decompressed size: " << result.size()     << " bytes\n";
    cout << "Saved to:          " << outPath           << "\n";

    if (ms > 0)
        cout << "Time taken:      " << ms << " ms\n";
    else
        cout << "Time taken:      " << us << " us\n";
}

void compressAndEncrypt() {
    cout << "\n-- SELECT INPUT FILE --\n";
    string inPath = FileHandler::pickFile(); //
    if (inPath.empty()) return;

    cout << "\n-- SELECT OUTPUT FILE --\n";
    string outPath = FileHandler::pickOutputPath(); //
    
    string input = FileHandler::readFile(inPath); //
    if (input.empty()) return;

    // Get Key
    cout << "Enter a secret encryption key: ";
    string key;
    getline(cin, key);

    //  Compression
    unordered_map<char, int> freqMap = getFrequencies(input);
    PriorityQueue pq;
    for (auto& x : freqMap) pq.push(new Node(x.first, x.second));

    HuffmanTree tree;
    tree.build(pq);
    string compressed = tree.compress(input); //

    // Encrypt (XOR with key)
    string encrypted = Encryptor::process(compressed, key);

    //  Save File
    FileHandler::writeFile(outPath, encrypted); //
    cout << "\nFile compressed and encrypted successfully!\n";
}

void decryptAndDecompress() {
    cout << "\n-- SELECT ENCRYPTED FILE --\n";
    string inPath = FileHandler::pickFile();
    if (inPath.empty()) return;

    cout << "\n-- SELECT OUTPUT PATH --\n";
    string outPath = FileHandler::pickOutputPath();
    if (outPath.empty()) return;

    string encryptedData = FileHandler::readFile(inPath);
    if (encryptedData.empty()) return;

    // Get Key
    cout << "Enter the secret key for decryption: ";
    string key;
    getline(cin, key);

    auto start = chrono::high_resolution_clock::now();

    // Step 1: Decrypt (XOR back to compressed state)
    string compressed = Encryptor::process(encryptedData, key);

    // Decompress
    HuffmanTree tree;
    string result = tree.decompress(compressed);

    auto end = chrono::high_resolution_clock::now();

    // Write file
    FileHandler::writeFile(outPath, result);

    auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "\nDecryption and Decompression complete!\n";
    cout << "Final size: " << result.size() << " bytes\n";
    if (ms > 0) cout << "Time taken: " << ms << " ms\n";
}

int main() {
    int choice;

    cout << "==============================\n";
    cout << "   Huffman Compression Tool   \n";
    cout << "==============================\n";
    cout << "1. Compress a file\n";
    cout << "2. Decompress a file\n";
    cout << "3. Encrypt a file\n";
    cout << "4. Decrypt a file\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: compressFile();   break;
        case 2: decompressFile(); break;
        case 3: compressAndEncrypt(); break;
        case 4: decryptAndDecompress(); break;
        default: cout << "Invalid choice.\n";
    }

    return 0;
}
