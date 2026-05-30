/*
MIT License

Copyright (c) 2026 darkyboys

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <filesystem>
#include   <iostream>
#include    <fstream>
#include     <string>
#include     <vector>

// Functions
void file(const std::string& name, const std::string& content){
    std::cout << "\033[92mBuilding "<<name<<"\n\033[0m";
    std::ofstream ofile(name);
    ofile << content;
}


void folder(const std::string& name, const std::string& content){
    std::cout << "\033[96mBuilding "<<name<<"\n\033[0m";
    std::ofstream ofile(name);
    ofile << content;
}



std::vector<std::string> getFilesInDirectory(const std::string& path) {
    namespace fs = std::filesystem;
    std::vector<std::string> files;

    try {
        if (!fs::exists(path) || !fs::is_directory(path)) {
            return files;
        }

        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_regular_file(entry.status())) {
                files.push_back(entry.path().filename().string());
            }
        }
    }
    catch (const fs::filesystem_error&) {
        // silently fail or handle error if needed
    }

    return files;
}


std::string url_encoder(const std::string& url){
    std::string output;
    for (char c : url){
        if (c == ' ') {output += "%20";continue;}
        if (c == '!') {output += "%21";continue;}
        output += c;
    }
    return output;
}