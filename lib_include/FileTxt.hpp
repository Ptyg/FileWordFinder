#ifndef FILE_TXT_H
#define FILE_TXT_H

// -------------------- This macros for extra features. Set to false(0) to disable ---------------------------

#ifndef DO_TIMER_FILE_TXT_FIND_WORD	
	#define DO_TIMER_FILE_TXT_FIND_WORD 1
#endif // DO_TIMER_FILE_TXT_FIND_WORD

#ifndef DO_WITH_ASYNC_TXT
	#define DO_WITH_ASYNC_TXT 1
#endif // DO_WITH_ASYNC_TXT

// -----------------------------------------------------------------------------------------------------------
#include "FileAbstract.hpp"
#include "outResultBase.hpp"

class FileTxt : public FileAbstract {
public:
	FileTxt(std::filesystem::path&& path, std::string&& findingWord = " ");
	FileTxt(const std::filesystem::path& path, const std::string& findingWord = " ");
	~FileTxt() = default;

	/* 
		Returns a vector with results

		@ const std::function<std::vector<std::filesystem::path>(
				const std::filesystem::path& dir, 
				const std::vector<std::string>& ext
			)>& func - function to collect files
 
		@ const std::filesystem::path& dir - path to folder where files will be collected
		@ const std::vector<std::string>& ext - files extentions 
	*/
	std::vector<OutResult> findWord(bool collect_recursivly = false);
};

#endif // FILE_TXT_H