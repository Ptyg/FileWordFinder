#ifndef FILE_TXT_H
#define FILE_TXT_H

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
	std::vector<OutResult> findWord(const std::function<std::vector<std::filesystem::path>(
													const std::filesystem::path& dir, 
													const std::vector<std::string>& ext)>& func);
};

#endif