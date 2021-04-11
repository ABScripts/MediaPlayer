#ifndef FILESEEKER_MANAGER_H
#define FILESEEKER_MANAGER_H

#include <filesystem>
#include <vector>
#include <string>
#include <set>

#include "include/fileseeker.h"

namespace fs = std::filesystem;

class FileseekerManager {
    
public:
    static std::set<std::string> retrieveFiles(const std::vector<std::string> &fileExtensions);

private:
    static std::string prettyFileExtension(const std::string &fileExtensions);
    static std::set<std::string> createFileExtensionsPack(const std::vector<std::string> &fileExtensions);

    static std::set<std::string> convertToStringPath(const std::set<fs::path> &paths);
};

#endif
