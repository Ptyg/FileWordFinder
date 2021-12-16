#pragma once
#include <filesystem>
#include <chrono>
#include "FileAbstract.h"
#include "task.h"

namespace fs = std::filesystem;

class FileTxt : public FileAbstract {
	string _word;
	const string _fileType = ".txt";
public:
	// функции override
	void displayFiles() override;
	void displayNotAllFiles() override;

	// функции НЕ override
	void findWordAll();
	void findWordNotAll();

	void setFindWord(string& word);
	string getFindWord();
};