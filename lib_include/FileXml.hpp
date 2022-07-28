#ifndef FILE_XML_H
#define FILE_XML_H

// -------------------- This macros for extra features. Set to false(0) to disable ---------------------------

#ifndef DO_TIMER_FILE_XML_FIND_OBJECT
	#define DO_TIMER_FILE_XML_FIND_OBJECT 1
#endif // DO_TIMER_FILE_XML_FIND_OBJECT

#ifndef DO_WITH_ASYNC_XML
	#define DO_WITH_ASYNC_XML 1
#endif // DO_WITH_ASYNC_XML

// -----------------------------------------------------------------------------------------------------------
#include "FileAbstract.hpp"
#include "OutResultXml.hpp"

class FileXml : public FileAbstract {
public:
	FileXml(std::filesystem::path&& path, std::string&& findingWord = " ");
	FileXml(const std::filesystem::path& path, const std::string& findingWord = " ");
	~FileXml() = default;

	/*
		Returns a vector with results
	
		@ bool collect_recursivly - collect files from subdirs or not
	*/
	std::vector<OutResultXml> findObject(bool collect_recursivly = false);
};

#endif
