#include "FileAbstract.hpp"
#include "getDirectoryFiles.hpp"
#include "getNotAllDirectoryFiles.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

std::string FileAbstract::getFileType() const { 
	return _fileType; 
}

void FileAbstract::setFindWord(const std::string& word) { 
	_word = word; 
}

void FileAbstract::setFindWord(std::string&& word){ 
	_word = std::move(word);
}

std::string FileAbstract::getFindWord() const { 
	return _word; 
}

void FileAbstract::setFileType(std::string&& type) { 
	_fileType = type; 
}

std::filesystem::path FileAbstract::enterPath() {
	std::string catalog;
	auto path = fs::current_path();

	std::cout << "\nCurrent path: " << path;
	std::cout << "\nEnter path to the dir\n(Attention! The path must be written without using Cyrillic characters)\n(If left as is - D): ";
	std::cin >> catalog;

	if (catalog != "D") { path = fs::path(catalog); }
	return path;
}