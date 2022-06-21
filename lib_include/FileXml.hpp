#ifndef FILE_XML_H
#define FILE_XML_H

#include "FileAbstract.hpp"
#include "outResultXml.hpp"

class FileXml : public FileAbstract {
public:
	FileXml(const std::string& findingWord, const std::filesystem::path& path);
	FileXml(const std::string& findingWord, std::filesystem::path&& path);
	FileXml(std::filesystem::path&& path, std::string&& findingWord = " ");
	FileXml(const std::filesystem::path& path, std::string&& findingWord = " ");
	~FileXml() = default;

	/* function takes a function that searches files in dir. Example of that func in getDirectoryFiles.cpp*/
	std::vector<OutResultXml> findObject(const std::function<std::vector<std::filesystem::path>(
												const std::filesystem::path& dir, 
												const std::vector<std::string>& ext)>& func);
};

#endif
