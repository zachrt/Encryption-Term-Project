#pragma once
#include <string>

class Encryptor {
public:
    static std::string process(const std::string& data, const std::string& key) {
        if (key.empty()) return data;
        std::string output = data;
        for (size_t i = 0; i < data.size(); ++i) {
            // XOR each byte with a character from the key
            output[i] = data[i] ^ key[i % key.length()];
        }
        return output;
    }
};