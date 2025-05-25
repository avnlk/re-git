#include <bits/stdc++.h>
using namespace std;

#include "create_directory.h"

bool createdirectory(const filesystem::path& path) {
    try {
        return filesystem::create_directories(path);
    } catch (filesystem::filesystem_error& e) {
        cerr << "Error creating directory " << path << ": " << e.what() << "\n";
        return false;
    }
}

