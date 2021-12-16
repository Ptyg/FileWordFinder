#pragma once
#include "task.h"

class FileUserType : public FileAbstract {
	string _word, _fileType = "";
public:
	// функции override
	void displayFiles() override;
	void displayNotAllFiles() override;

	// функции НЕ override
	void setFileType(string& fileType);
	string getFileType();

	void findWord();
	void findWordNotAll();
};