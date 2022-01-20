#ifndef VECTOR
#define	VECTOR	
#include <vector>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef FILESYSTEM
#define FILESYSTEM
#include <filesystem>
namespace fs = std::filesystem;
#endif

#ifndef GET_DIR_FILES_H
#define GET_DIR_FILES_H

std::vector<std::string> getDirectoryFiles(const fs::path& dir, const std::vector<std::string>& ext);

#endif
