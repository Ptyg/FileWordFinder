#include "FileAbstract.hpp"
#include "getNotAllDirectoryFiles.hpp"
#include "getDirectoryFiles.hpp"
#include "Log.hpp"
#include <iostream>
#include <memory>
#include <format>

std::filesystem::path FileAbstract::getDirPath() const{
	return _dirPath;
}

std::string FileAbstract::getFileType() const{ 
	return _fileType; 
}

std::string FileAbstract::getFindWord() const { 
	return _word; 
}

void FileAbstract::setFileType(const std::string& type){
	_fileType = type;
}

void FileAbstract::setFindWord(const std::string& word){ 
	_word = word; 
}

void FileAbstract::setFindWord(std::string&& word){ 
	_word = std::move(word);
}

void FileAbstract::setFileType(std::string&& type) { 
	_fileType = std::move(type); 
}

void FileAbstract::setPath(const std::filesystem::path& path){
	_dirPath = path;
}

void FileAbstract::setPath(std::filesystem::path&& path){
	_dirPath = std::move(path);
}

std::vector<std::filesystem::path> FileAbstract::collectFiles(const std::function<std::vector<std::filesystem::path>(
															  		const std::filesystem::path& dir, 
															  		const std::vector<std::string>& ext)>& func)
{
	Log::console_log("Collecting files...");
	const auto files = func(getDirPath(), { getFileType() });
	Log::console_log(std::format("Collecting has been completed. Number of files: {}", files.size()));
	return files;
}