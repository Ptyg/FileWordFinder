#include "FileAbstract.h"

#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef FILESYSTEM
#define FILESYSTEM
#include <filesystem>
namespace fs = std::filesystem;
#endif

#ifndef CHRONO
#define CHRONO
#include <chrono>
#endif

#ifndef GET_DIR_FILES_H
#define GET_DIR_FILES_H
#include "getDirectoryFiles.h"
#endif

#ifndef GET_NOT_DIR_FILES_H
#define GET_NOT_DIR_FILES_H
#include "getNotAllDirectoryFiles.h"
#endif

const std::string& FileAbstract::getFileType() const { return _fileType; }
void FileAbstract::setFindWord(std::string& word) { _word = word; }
const std::string& FileAbstract::getFindWord() const { return _word; }
void FileAbstract::setFileType(std::string type) { _fileType = type; }

std::filesystem::path FileAbstract::enterPath() {
	std::string catalog;
	auto path = fs::current_path();

	std::cout << "\nCurrent path: " << path;
	printf("\nEnter path to the dir\n(Attention! The path must be written without using Cyrillic characters)\n(If left as is - D): ");
	std::cin >> catalog;

	if (catalog != "D") { path = fs::path(catalog); }
	return path;
}

void FileAbstract::displayFiles() {
	system("cls");
	
	const std::filesystem::path path = enterPath();

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector)
			std::cout << f << "\n";
		std::cout << "\nNumber of files: " << aVector.size();
	};

	auto files = getDirectoryFiles(path, { getFileType() });
	print_files(files);
}
void FileAbstract::displayNotAllFiles() {
	system("cls");
	
	const std::filesystem::path path = enterPath();

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector)
			std::cout << f << "\n";
		std::cout << "\nNumber of files: " << aVector.size();
	};

	auto files = getNotAllDirectoryFiles(path, { getFileType() });
	print_files(files);
}

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