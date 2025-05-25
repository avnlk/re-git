#include <bits/stdc++.h>
using namespace std;

#include "create_file.h"

bool create_file(const filesystem::path& filepath,const string& content) {
    ofstream file(filepath);
    if (!file) {
        cerr << "Error creating file: " << filepath << "\n";
        return false;
    }
    file << content;
    return true;
}

