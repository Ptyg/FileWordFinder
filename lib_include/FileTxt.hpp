#ifndef FILE_TXT_H
#define FILE_TXT_H

#include "FileAbstract.hpp"

#include <functional>

class FileTxt : public FileAbstract {
	
public:
	FileTxt();
	FileTxt(const std::string& findingWord);
	FileTxt(std::string&& findingWord);
	FileTxt(const std::filesystem::path& path);
	FileTxt(std::filesystem::path&& path);
	FileTxt(const std::string& findingWord, const std::filesystem::path& path);
	FileTxt(const std::string& findingWord, std::filesystem::path&& path);
	FileTxt(std::string&& findingWord, std::filesystem::path&& path);
	FileTxt(std::string&& findingWord, const std::filesystem::path& path);
	~FileTxt() = default;

	/* function takes a function that searches files in dir. Example of that func in getDirectoryFiles.cpp*/
	void findWord(const std::function<std::vector<std::string>(const fs::path& dir, 
															   const std::vector<std::string>& ext)>& func);

	struct OutResult{
		OutResult() = default;
		
		OutResult(std::string&& findWord, std::string&& file, 
				  std::string&& line, int&& lineNumber)
		: _findWord(std::move(findWord)), _currentFile(std::move(file)), 
		_line(std::move(line)), _lineNumber(std::move(lineNumber)) {}
		
		OutResult(const std::string& findWord, const std::string& file,
				  const std::string& line, const int& lineNumber) 
		: _findWord(findWord), _currentFile(file), _line(line), _lineNumber(lineNumber) {}

		std::string _findWord;
		std::string _currentFile;
		std::string _line;
		int _lineNumber;
	};
};

#endif