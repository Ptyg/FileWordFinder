#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef FILE_XML_H
#define FILE_XML_H

#include "FileAbstract.h"

class FileXml : public FileAbstract {
	std::string _word;
	const std::string _fileType = ".xml";
public:
	void displayFiles() override;
	void displayNotAllFiles() override;

	void findWordAll();
	void findWordNotAll();

	const std::string& getFileType() const;

	void setFindWord(std::string& word);
	std::string getFindWord();
};

#endif
