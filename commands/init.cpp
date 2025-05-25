#include <bits/stdc++.h>
#include "utils.h"

using namespace std;
using namespace filesystem;

bool run_init() {
    path repo_root = current_path() / ".re-git";

    // If already initialized, do nothing
    if (exists(repo_root)) {
        cout << "re-git repository already exists at " << repo_root << "\n";
        return false;
    }

    // Create top-level .re-git directory
    if (!createdirectory(repo_root)) return false;

    // Core directories
    vector<path> dirs = {
        "branches",
        "info",
        "objects/info",
        "objects/pack",
        "refs/heads",
        "refs/tags"
    };

    for (const auto& dir : dirs) {
        if (!createdirectory(repo_root / dir)) return false;
    }

    // Core files
    if (!create_file(repo_root / "HEAD", "ref: refs/heads/main\n")) return false;

    string config_content = R"(
[core]
    repositoryformatversion = 0
    filemode = true
    bare = false
)";
    if (!create_file(repo_root / "config", config_content)) return false;
    if (!create_file(repo_root / "description", "Unnamed repository; edit this file to name the repository.\n")) return false;
    if (!create_file(repo_root / "info/exclude", "# Add patterns to ignore\n")) return false;

    return true;
}

