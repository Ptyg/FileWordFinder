#ifndef OUT_RESULT_BASE
#define OUT_RESULT_BASE

#include <string>
#include <filesystem>

/*
Basic data structure for result that we get from finding word
*/
class OutResult{
public:
	std::string m_findWord;
	std::string m_filePath;
	std::string m_line;
	int m_lineNumber;
		
	OutResult(std::string&& findWord, std::string&& file, 
			  std::string&& line, int lineNumber)
	: m_findWord(std::move(findWord)), m_filePath(std::move(file)), 
	m_line(line), m_lineNumber(std::move(lineNumber)) {}
};
#endif