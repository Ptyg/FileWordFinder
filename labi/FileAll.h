#pragma once
#include "task.h"

namespace fs = std::filesystem;

class FileAll : public FileAbstract{
	string _word;
public:
	void displayFiles() override;
	void displayNotAllFiles() override;

	void findWordAll();
	void findWordNotAll();
};