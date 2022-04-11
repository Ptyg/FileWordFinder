#ifndef FILE_TXT_H
#define FILE_TXT_H

#include "FileAbstract.hpp"

class FileTxt : public FileAbstract {
public:
	FileTxt();
	~FileTxt();

	void findWordAll();
	void findWordNotAll();
};

#endif