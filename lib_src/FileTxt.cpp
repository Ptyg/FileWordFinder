#include "FileTxt.hpp"
#include "getDirectoryFiles.hpp"

#include <iostream>
#include <memory>

FileTxt::FileTxt(std::string_view findingWord, std::string_view path) {
	m_word = findingWord;
	m_fileTypes = { ".txt" };
	m_dirPath = path;
}
