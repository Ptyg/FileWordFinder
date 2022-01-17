#ifndef INCLUDES_FOR_FILESEARCHING
#define INCLUDES_FOR_FILESEARCHING

#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

#endif 

#ifndef GET_DIR_FILES_H
#define GET_DIR_FILES_H

std::vector<std::string> getDirectoryFiles(const fs::path& dir, const std::vector<std::string>& ext);

#endif
