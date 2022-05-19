#ifndef OUT_RESULT_TXT
#define OUT_RESULT_TXT

#include <string>

/*
Data structure for result that we get from finding word in txts
*/
class OutResult{
	std::string _findWord;
	std::string _filePath;
	std::string _line;
	int _lineNumber;
public:
    OutResult() = default;
		
	OutResult(std::string&& findWord, std::string&& file, 
			  std::string&& line, int&& lineNumber)
	: _findWord(std::move(findWord)), _filePath(std::move(file)), 
	_line(std::move(line)), _lineNumber(std::move(lineNumber)) {}
	
	OutResult(const std::string& findWord, const std::string& file,
			  const std::string& line, const int& lineNumber) 
	: _findWord(findWord), _filePath(file), _line(line), _lineNumber(lineNumber) {}

    std::string getFindWord() const;
    std::string getfilePath() const;
    std::string	getLine() const;
    int getLineNumber() const;
};
#endif