#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

std::vector<std::string> getDirectoryFiles(const fs::path& dir, const std::vector<std::string>& ext);

