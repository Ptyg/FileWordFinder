#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H

#include <string>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;

class FileAbstract {
	std::string _word;
	std::string _fileType = "";

public:
	virtual ~FileAbstract() {};

	void displayFiles();
	void displayNotAllFiles();

	std::filesystem::path enterPath();

	const std::string& getFileType() const;
	void setFileType(std::string type);

	void setFindWord(std::string& word);
	const std::string& getFindWord() const;

	class SaveFile {
	public:
		std::string _fileName;
		static void saveInfoTxt(std::string, std::string, int&, std::string&, FileAbstract::SaveFile);
		static void saveInfoHtml(std::vector<std::string>, std::string, int&, std::string&, FileAbstract::SaveFile);
		static void saveInfoXml(std::string, std::string, int&, std::string&, FileAbstract::SaveFile, std::vector<std::string>&);
	};
};

#endif