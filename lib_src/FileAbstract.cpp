#include "FileAbstract.hpp"
#include "getNotAllDirectoryFiles.hpp"
#include "getDirectoryFiles.hpp"
#include <iostream>
#include <memory>


std::vector<std::filesystem::path> FileAbstract::collectFiles(const std::function<std::vector<std::filesystem::path>(
															  const std::filesystem::path& dir, 
															  const std::vector<std::string>& ext)>& func)
{
	std::cout << "[INFO]: Collecting files...\n";
	const auto files = func(_dirPath, { _fileType });
	std::cout << "[INFO]: Collecting has been completed. Number of files: " << files.size() << '\n';
	return files;
}