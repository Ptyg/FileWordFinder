#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H
class FileAbstract {
	std::string _word;
	std::string _fileType = "";
public:
	virtual ~FileAbstract() {};

	virtual void displayFiles();
	virtual void displayNotAllFiles();

	// stub 
	virtual void findWordAll() {};
	virtual void findWordNotAll() {};
	// 

	const std::string& getFileType() const;
	void setFileType(std::string type);

	void setFindWord(std::string& word);
	const std::string& getFindWord() const;

	struct SaveFile {
		std::string _fileName;
		static void saveInfoTxt(std::string, std::string, int&, std::string&, FileAbstract::SaveFile);
		static void saveInfoHtml(std::vector<std::string>, std::string, int&, std::string&, FileAbstract::SaveFile);
		static void saveInfoXml(std::string, std::string, int&, std::string&, FileAbstract::SaveFile, std::vector<std::string>&);
	};
};

#endif