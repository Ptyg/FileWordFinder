#ifndef FILE_TXT_H
#define FILE_TXT_H

#include "FileAbstract.hpp"
#include "outResultBase.hpp"

class FileTxt : public FileAbstract {
public:
	FileTxt(std::string_view findingWord, std::string_view path);

	template<typename iterator = std::filesystem::directory_iterator>
	std::vector<OutResult> findWord();
};

#endif