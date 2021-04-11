#include "include/fileseeker.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

#ifdef _WIN32
#include <Windows.h>
#include < string.h >
#endif

std::set<fs::path> Fileseeker::getFilesByExtension(std::set<std::string> fileExtensions)
{
    std::set<fs::path> foundFiles;
    auto foundFilesIterator = foundFiles.end();

    std::set<fs::path> rootPaths = getRootPaths();

    for (const auto &rootPath : rootPaths)
    {
        fs::recursive_directory_iterator begin(rootPath, fs::directory_options::skip_permission_denied);

        fs::recursive_directory_iterator end;

        std::error_code os_error;

        std::copy_if(begin.increment(os_error),
                     // use increment with os_error to determine errors like "no such file
                     // or directory" as it couldn`t be handled manually in this case
                     end, // could also use fs::end(begin) but I feel that this is kinda messy code ?
                     std::inserter<std::set<fs::path>>(foundFiles, foundFilesIterator),
                     [&fileExtensions, &os_error](const fs::path& path) {

            if (!os_error)
            {
                if (fs::is_regular_file(path, os_error))
                {
                    if (!os_error)
                    {

                        for (const auto &fileExtension : fileExtensions)
                        {
                            if (path.extension() == fileExtension)
                            {
                                return true;
                            }
                        }
                    }
                }
            }

            os_error.clear();

            return false;
        }   );
    }

    return foundFiles;
}

std::set<fs::path> Fileseeker::getRootPaths()
{
    std::set<fs::path> rootPaths;

#ifdef __linux__
    rootPaths.insert(fs::current_path().root_path());
#elif _WIN32
    const unsigned char buffSize = 255;
    const char backslash = '\\';

    char buffer[buffSize];

    ::GetLogicalDriveStringsA (buffSize, buffer);
    char *driveLetterPtr = buffer;

    std::string retval;

    // I feel like this "low-level" code should be placed in different module like "Converter" or so,
    // because the next part is pretty much "high-level" dealing with std::algorithms ?
    while (*driveLetterPtr)
    {
        retval += driveLetterPtr;
        driveLetterPtr += strlen (driveLetterPtr)+1;
    }

    while (!retval.empty())
    {
        auto backSlashIndex = retval.find(backslash);

        if (backSlashIndex != std::string::npos)
        {
            std::string rootPath;

            std::copy(retval.begin(),
                      retval.begin() + backSlashIndex + 1,
                      std::back_inserter(rootPath));

            rootPaths.insert(rootPath);

            retval.erase(retval.begin(), retval.begin() + backSlashIndex + 1);
        }
        else
        {
            break;
        }
    }
#endif

    return rootPaths;
}
