#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H

#include <string_view>
#include <vector>
#include <functional>
#include <filesystem>

class FileAbstract {
public:
	std::string_view m_word;
	std::vector<std::string_view> m_fileTypes;
	std::filesystem::path m_dirPath; 
	
	virtual ~FileAbstract() = default;
};

#endif