#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H

#include <string>
#include <vector>
#include <functional>
#include <filesystem>

#ifndef DO_TIMER_FILE_ABSTRACT_GET_DIR_FILES
	#define DO_TIMER_FILE_ABSTRACT_GET_DIR_FILES 1
#endif // DO_TIMER_FILE_ABSTRACT_GET_DIR_FILES

class FileAbstract {
protected:
	std::string _word{};
	std::string _extention{};
	std::filesystem::path _path{}; 
public:
	virtual ~FileAbstract() = default;

	/*
		Returns a vector with paths to files

		@ bool collect_recursivly = false
	*/
	
	std::vector<std::filesystem::path> getDirectoryFiles(bool collect_recursivly = false);
};

#endif