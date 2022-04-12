#ifndef FILE_XML_H
#define FILE_XML_H

#include "FileAbstract.hpp"

class FileXml : public FileAbstract {
public:
	FileXml();
	FileXml(const std::string& findingWord);
	FileXml(std::string&& findingWord);
	~FileXml() = default;

	void showResultsFromAllDirs();
	void showResultsFromNotAllDirs();
};

#endif
