#ifndef CREATE_FILE_H
#define CREATE_FILE_H

#include <string>
#include <filesystem>
using namespace std;

bool create_file(const filesystem::path& filepath, const string& content = "");

#endif 

