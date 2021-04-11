#ifndef FILESEEKER_H
#define FILESEEKER_H

#include <filesystem>
#include <string>
#include <vector>
#include <set>

namespace fs = std::filesystem;

class Fileseeker {

public:
    static std::set<fs::path> getFilesByExtension(std::set<std::string> fileExtensions);

    static std::set<fs::path> getRootPaths();
};

#endif
