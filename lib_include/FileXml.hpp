#ifndef FILE_XML_H
#define FILE_XML_H

#include "FileAbstract.hpp"
#include "outResultXml.hpp"

class FileXml : public FileAbstract {
public:
	FileXml(std::string_view findingWord, std::string_view path);

	template<typename iterator = std::filesystem::directory_iterator>
	std::vector<OutResultXml> findObject();
};

#endif
