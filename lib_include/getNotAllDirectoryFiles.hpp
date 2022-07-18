#include <vector>
#include <string>
#include <filesystem>

/*
    Returns paths to files with specified extension

    @ const std::filesystem::path& dir - path to directory
    @ const std::vector<std::string>& ext - vector of extensions // {".txt", ".xml", ...}

    p.s: work without using recursive
*/
std::vector<std::filesystem::path> getNotAllDirectoryFiles(const std::filesystem::path& dir, 
                                                           const std::vector<std::string>& ext);