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
public:
	virtual ~FileAbstract() {};

	virtual void displayFiles() = 0;
	virtual void displayNotAllFiles() = 0;

	struct SaveFile {
		std::string _fileName;
		static void saveInfoTxt(std::string, std::string, int&, std::string&, FileAbstract::SaveFile);
		static void saveInfoHtml(std::vector<std::string>, std::string, int&, std::string&, FileAbstract::SaveFile);
		static void saveInfoXml(std::string, std::string, int&, std::string&, FileAbstract::SaveFile, std::vector<std::string>&);
	};
};

#endif