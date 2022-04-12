#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H

#include <string>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;

class FileAbstract {
	std::string _word;
	static std::string _fileType;
	std::filesystem::path _dirPath; 
public:
	virtual ~FileAbstract() = default;

	void setPath();
	std::string getFileType() const;
	std::string getFindWord() const;
	std::string getDirPath() const;

	void setDirPath();
	static void setFileType(std::string&& type) noexcept;
	static void setFileType(const std::string& type);
	void setFindWord(std::string&& word) noexcept;
	void setFindWord(const std::string& word);
};

#endif