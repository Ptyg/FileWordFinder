#include "FileAbstract.h"
#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

void FileAbstract::SaveFile::saveInfoTxt(std::string word, std::string path, int& lineNum, std::string& line, FileAbstract::SaveFile obj) {
	std::ofstream fout;
	try{
		fout.open(obj._fileName, std::ofstream::app);
		fout << "Word: " << word << "\n";
		fout << "Path: " << path << "\n";
		fout << "Line number: " << lineNum << "\n";
		fout << "Line: " << line << "\n\n";
		std::cout << "Data has been saved\n";
		fout.close();
	}
	catch (const std::exception& ex) { std::cout << ex.what() << "\n"; fout.close(); }
}
void FileAbstract::SaveFile::saveInfoHtml(std::vector<std::string> word, std::string path, int& lineNum, std::string& line, FileAbstract::SaveFile obj) {
	std::ofstream fout;
	try {
		fout.open(obj._fileName, std::ofstream::app);
		fout << "Words: ";
		for (int i = 0; i < word.size(); i++) { fout << word[i] << ' '; } std::cout << "\n\n";
		fout << "Path: " << path << "\n";
		fout << "Line number: " << lineNum << "\n";
		fout << "Line: " << line << "\n\n";
		std::cout << "Data has been saved\n";
		fout.close();
	}
	catch (const std::exception& ex) { std::cout << ex.what() << "\n"; fout.close(); }
}
void FileAbstract::SaveFile::saveInfoXml(std::string tag, std::string path, int& lineNum, std::string& line, FileAbstract::SaveFile obj, std::vector<std::string>& objcts) {
	std::ofstream fout;
	try {
		fout.open(obj._fileName, std::ofstream::app);
		fout << "Objects: ";
		for (int i = 0; i < objcts.size(); i++) { fout << objcts[i] << ' '; }; fout << "\n";
		fout << "Tag: " << tag; 
		for (int i = 0; i < tag.size(); i++) { if (tag[i] == '<') { tag.insert(i + 1, std::string("/")); break; }}
		fout << tag << "\n";
		fout << "Path: " << path << "\n";
		fout << "Line number: " << lineNum << "\n";
		fout << "Line: " << line << "\n\n";
		std::cout << "Data has been saved\n";
		fout.close();
	}
	catch (const std::exception& ex) { std::cout << ex.what() << "\n"; fout.close(); }
}