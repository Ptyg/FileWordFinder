#include <vector>
#include <filesystem>

template<typename iterator, typename path, typename iteratable_vect>
std::vector<std::filesystem::path> getDirectoryFiles(path&& dir, iteratable_vect&& ext);

