#pragma once
#include <filesystem>
#include <chrono>
#include "FileAbstract.h"
#include "task.h"

class FileXml : public FileAbstract {
	string _word, _fileType = ".xml";
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
