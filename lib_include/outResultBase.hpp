#ifndef OUT_RESULT_BASE
#define OUT_RESULT_BASE

#include <string>
#include <filesystem>

/*
Basic data structure for result that we get from finding word
*/
class OutResult{
	std::string _findWord;
	std::filesystem::path _filePath;
	std::string _line;
	int _lineNumber;
public:
    OutResult() = default;
		
	OutResult(std::string&& findWord, std::filesystem::path&& file, 
			  std::string&& line, int&& lineNumber)
	: _findWord(std::move(findWord)), _filePath(std::move(file)), 
	_line(std::move(line)), _lineNumber(std::move(lineNumber)) {}
	
	OutResult(const std::string& findWord, const std::filesystem::path& file,
			  const std::string& line, const int& lineNumber) 
	: _findWord(findWord), _filePath(file), _line(line), _lineNumber(lineNumber) {}

    std::string getFindWord() const;
    std::filesystem::path getfilePath() const;
    std::string	getLine() const;
    int getLineNumber() const;
};
#endif