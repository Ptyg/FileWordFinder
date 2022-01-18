#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef FILE_TXT_H
#define FILE_TXT_H

#include "FileAbstract.h"

class FileTxt : public FileAbstract {
	std::string _word;
	const std::string _fileType = ".txt";
public:
	// функции override
	void displayFiles() override;
	void displayNotAllFiles() override;

	// функции НЕ override
	void findWordAll();
	void findWordNotAll();

	const std::string& getFileType() const;

	void setFindWord(std::string& word);
	std::string getFindWord();
};

#endif