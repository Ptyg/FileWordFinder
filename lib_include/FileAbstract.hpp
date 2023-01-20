#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H

#include <string_view>
#include <vector>
#include <functional>
#include <filesystem>

class FileAbstract {
public:
	std::string_view m_word;
	std::vector<std::string_view> m_fileTypes;
	std::filesystem::path m_dirPath; 
	
	virtual ~FileAbstract() = default;

	/* function takes a function that searches files in dir. Example of that func in getDirectoryFiles.cpp*/
	std::vector<std::filesystem::path> collectFiles(const std::function<std::vector<std::filesystem::path>(
													const std::filesystem::path& dir, 
													const std::vector<std::string_view>& ext)>& func);
};

#endif