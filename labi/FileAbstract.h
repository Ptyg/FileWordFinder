#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;


class FileAbstract {
public:
	virtual ~FileAbstract() {};

	virtual void displayFiles() = 0;
	virtual void displayNotAllFiles() = 0;

	struct SaveFile {
		string _fileName;
		static void saveInfo(string word, string path, int& lineNum, string& line, FileAbstract::SaveFile obj);
		static void saveInfo2(vector<string> word, string path, int& lineNum, string& line, FileAbstract::SaveFile obj);
		static void saveInfo3(string tag, string path, int& lineNum, string& line, FileAbstract::SaveFile obj);
	};
};