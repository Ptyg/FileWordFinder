#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H

#include <string>
#include <vector>
#include <functional>
#include <filesystem>

class FileAbstract {
protected:
	std::string _word{};
	std::string _extention{};
	std::filesystem::path _path{}; 
public:
	virtual ~FileAbstract() = default;

	/*
		Returns a vector with paths to files

		@ bool collect_recursivly = false
	*/
	
	std::vector<std::filesystem::path> getDirectoryFiles(bool collect_recursivly = false);
};

#endif