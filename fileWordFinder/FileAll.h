#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef FILE_ALL_H
#define FILE_ALL_H

#include "FileAbstract.h"

class FileAll : public FileAbstract{
	//std::string _word;
public:
	//void displayFiles() override;
	//void displayNotAllFiles() override;

	void findWordAll();
	void findWordNotAll();
};

#endif