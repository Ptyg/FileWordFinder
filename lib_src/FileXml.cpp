#include "FileXml.hpp"
#include "Log.hpp"

#include <iostream>
#include <fstream>
#include <memory>

FileXml::FileXml(std::string_view findingWord, std::string_view path) {
	m_word = findingWord;
	m_fileTypes = { ".xml" };
	m_dirPath = path;
}
