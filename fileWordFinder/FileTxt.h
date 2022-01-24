#ifndef FILE_TXT_H
#define FILE_TXT_H

#include "FileAbstract.h"

class FileTxt : public FileAbstract {
public:
	FileTxt();
	~FileTxt();

	void findWordAll();
	void findWordNotAll();
};

#endif