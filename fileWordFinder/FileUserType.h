#ifndef FILE_USER_TYPE_H 
#define FILE_USER_TYPE_H

#include "FileAbstract.h"

class FileUserType : public FileAbstract {
public:
	void findWord();
	void findWordNotAll();
};

#endif