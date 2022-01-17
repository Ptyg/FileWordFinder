#ifndef INCLUDES_FOR_FILESEARCHING
#define INCLUDES_FOR_FILESEARCHING

#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

#endif 


#ifndef GET_NOT_DIR_FILES_H
#define GET_NOT_DIR_FILES_H

std::vector<std::string> getNotAllDirectoryFiles(const fs::path& dir, const std::vector<std::string>& ext);

#endif