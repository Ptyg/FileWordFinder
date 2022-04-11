#ifndef FILE_USER_TYPE_H 
#define FILE_USER_TYPE_H

#include "FileAbstract.hpp"

class FileUserType : public FileAbstract {
public:
	void findWord();
	void findWordNotAll();
};

#endif