#ifndef FILE_TXT_H
#define FILE_TXT_H

#include "FileAbstract.hpp"
#include "outResultBase.hpp"

class FileTxt : public FileAbstract {
public:
	FileTxt(std::string_view findingWord, std::string_view path);
	~FileTxt() = default;

	/* function takes a function that searches files in dir. Example of that func in getDirectoryFiles.cpp*/
	std::vector<OutResult> findWord(const std::function<std::vector<std::filesystem::path>(
													const std::filesystem::path& dir, 
													const std::vector<std::string_view>& ext)>& func);
};

#endif