#include <bits/stdc++.h>
using namespace std;

#include "utils.h"  

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: re-git <command>\n";
        cout << "Available commands:\n";
        cout << "  init    Initialize a new gitngithub repository\n";
        return 1;
    }

    string command = argv[1];

    if (command == "init") {
        if (run_init()) {
            cout << "Initialized empty re-git repository in " << filesystem::current_path() / ".re-git" << "\n";
            return 0;
        } else {
            cerr << "Failed to initialize repository.\n";
            return 1;
        }
    } else {
        cerr << "Unknown command: " << command << "\n";
        cout << "Usage: ./re-git <command>\n";
        return 1;
    }
}

