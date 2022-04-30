#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H

#include <string>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;

class FileAbstract {
	std::string _word;
	std::string _fileType;
	std::filesystem::path _dirPath; 
public:
	virtual ~FileAbstract() = default;

	void setPath();
	std::string getFileType() const;
	std::string getFindWord() const;
	std::filesystem::path getDirPath() const;

	void setFileType(std::string&& type);
	void setFileType(const std::string& type);
	void setFindWord(std::string&& word);
	void setFindWord(const std::string& word);
};

#endif