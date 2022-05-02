#ifndef FILE_TXT_H
#define FILE_TXT_H

#include "FileAbstract.hpp"

#include <functional>

class FileTxt : public FileAbstract {
	
public:
	FileTxt();
	FileTxt(const std::string& findingWord);
	FileTxt(std::string&& findingWord);
	~FileTxt() = default;

	void showResultsFromAllDirs();
	void showResultsFromNotAllDirs();
	void showFilesInDir(const std::function<std::vector<std::string>(const fs::path& dir, 
																	const std::vector<std::string>& ext)>& func);
};

#endif