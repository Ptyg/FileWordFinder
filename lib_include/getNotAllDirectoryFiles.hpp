#include <vector>
#include <string>
#include <filesystem>

std::vector<std::filesystem::path> getNotAllDirectoryFiles(const std::filesystem::path& dir, 
                                                           const std::vector<std::string>& ext);