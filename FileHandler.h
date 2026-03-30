#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>

using namespace std;

class FileHandler {
public:
    static string readFile(const string& path);
    static void writeFile(const string& path, const string& data);
    static string pickFile();
    static string pickOutputPath();
};