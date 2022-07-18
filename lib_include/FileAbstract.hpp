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

	/*
		Returns a vector with paths to files

		@ const std::function<std::vector<std::filesystem::path>(
				const std::filesystem::path& dir,
				const std::vector<std::string>& ext
			)& func - function to collect files

		@ const std::filesystem::path& dir - path to folder where files will be collected
		@ const std::vector<std::string>& ext - files extentions
	*/
	std::vector<std::filesystem::path> collectFiles(const std::function<std::vector<std::filesystem::path>(
															const std::filesystem::path& dir, 
															const std::vector<std::string>& ext)>& func);
};

#endif