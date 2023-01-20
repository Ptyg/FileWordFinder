#include <vector>
#include <filesystem>
#include <string_view>

std::vector<std::filesystem::path> getNotAllDirectoryFiles(const std::filesystem::path& dir, 
                                                           const std::vector<std::string_view>& ext);