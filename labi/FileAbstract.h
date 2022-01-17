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
		static void saveInfo(std::string word, std::string path, int& lineNum, std::string& line, FileAbstract::SaveFile obj);
		static void saveInfo2(std::vector<std::string> word, std::string path, int& lineNum, std::string& line, FileAbstract::SaveFile obj);
		static void saveInfo3(std::string tag, std::string path, int& lineNum, std::string& line, FileAbstract::SaveFile obj);
	};
};

#endif