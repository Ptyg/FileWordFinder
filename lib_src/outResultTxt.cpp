#include "outResultTxt.hpp"

std::string OutResult::getFindWord() const{
    return _findWord;
}

std::string OutResult::getfilePath() const{
    return _filePath;
}

std::string	OutResult::getLine() const{
    return _line;
}

int getLineNumber() const{
	return _lineNumber;
}