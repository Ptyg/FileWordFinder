#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H

#include <string>
#include <vector>
#include <functional>
#include <filesystem>

class FileAbstract {
	std::string _word;
	std::string _fileType;
	std::filesystem::path _dirPath; 
public:
	virtual ~FileAbstract() = default;

	std::string getFileType() const;
	std::string getFindWord() const;
	std::filesystem::path getDirPath() const;

	void setPath(const std::filesystem::path& path);
	void setPath(std::filesystem::path&& path);
	void setFileType(std::string&& type);
	void setFileType(const std::string& type);
	void setFindWord(std::string&& word);
	void setFindWord(const std::string& word);

	/* function takes a function that searches files in dir. Example of that func in getDirectoryFiles.cpp*/
	std::vector<std::filesystem::path> collectFiles(const std::function<std::vector<std::filesystem::path>(
													const std::filesystem::path& dir, 
													const std::vector<std::string>& ext)>& func);

};

#endif