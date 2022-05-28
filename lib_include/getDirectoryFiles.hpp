#include <vector>
#include <string>
#include <filesystem>

std::vector<std::filesystem::path> getDirectoryFiles(const std::filesystem::path& dir, 
                                                     const std::vector<std::string>& ext);

