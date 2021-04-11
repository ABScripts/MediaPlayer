#include "include/fileseeker_manager.h"

std::string FileseekerManager::prettyFileExtension(const std::string &fileExtension) 
{
    const char extensionBeginSpec = '.';

    std::string prettierFileExtension;
    if (fileExtension.front() != extensionBeginSpec)
    {
        prettierFileExtension += extensionBeginSpec;
    }

    return (prettierFileExtension + fileExtension);
}

std::set<std::string> FileseekerManager::createFileExtensionsPack(const std::vector<std::string> &fileExtensions)
{
    std::set<std::string> fileExtensionsPack;

    for (auto &fileExtension : fileExtensions)
    {
        fileExtensionsPack.insert( prettyFileExtension(fileExtension) );
    }

    return fileExtensionsPack;
}

std::set<std::string> FileseekerManager::retrieveFiles(const std::vector<std::string> &fileExtensions)
{
    std::set<std::string> fileExtensionsPack = createFileExtensionsPack(fileExtensions);

    return convertToStringPath( Fileseeker::getFilesByExtension(fileExtensionsPack) );
}

std::set<std::string> FileseekerManager::convertToStringPath(const std::set<fs::path> &paths)
{
    std::set<std::string> filePaths;

    for (auto &path : paths)
    {
        filePaths.insert( path.string() );
    }

    return filePaths;
}
