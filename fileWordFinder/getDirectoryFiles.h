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

std::vector<std::string> getDirectoryFiles(const fs::path& dir, const std::vector<std::string>& ext);

