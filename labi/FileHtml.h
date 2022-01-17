#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef FILE_HTML_H
#define FILE_HTML_H

#include "FileAbstract.h"

class FileHtml : public FileAbstract {
	std::string _word;
	const std::string _fileType = ".html";
public:
	// функции override
	void displayFiles() override;
	void displayNotAllFiles() override;

	const std::string& getFileType() const;

	void setFindWord(std::string& word);
	std::string getFindWord();
};

#endif