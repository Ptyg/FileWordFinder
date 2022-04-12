#ifndef FILE_TXT_H
#define FILE_TXT_H

#include "FileAbstract.hpp"

class FileTxt : public FileAbstract {
	
public:
	FileTxt();
	FileTxt(const std::string& findingWord);
	FileTxt(std::string&& findingWord) noexcept;
	~FileTxt() = default;

	void showResultsFromAllDirs();
	void showResultsFromNotAllDirs();
};

#endif