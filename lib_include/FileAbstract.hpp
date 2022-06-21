#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H

#include <string>
#include <vector>
#include <functional>
#include <filesystem>

class FileAbstract {
protected:
	std::string _word{};
	std::string _fileType{};
	std::filesystem::path _dirPath{}; 
public:
	virtual ~FileAbstract() = default;

	/* function takes a function that searches files in dir. Example of that func in getDirectoryFiles.cpp*/
	std::vector<std::filesystem::path> collectFiles(const std::function<std::vector<std::filesystem::path>(
															const std::filesystem::path& dir, 
															const std::vector<std::string>& ext)>& func);
};

#endif