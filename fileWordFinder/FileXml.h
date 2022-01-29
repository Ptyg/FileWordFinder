#ifndef FILE_XML_H
#define FILE_XML_H

#include "FileAbstract.h"

class FileXml : public FileAbstract {
public:
	FileXml();
	~FileXml();

	void findObject();
	void findNotAllObject();
};

#endif
