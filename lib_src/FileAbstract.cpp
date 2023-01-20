#include "FileAbstract.hpp"
#include "getNotAllDirectoryFiles.hpp"
#include "getDirectoryFiles.hpp"
#include "Log.hpp"

#include <format>

std::vector<std::filesystem::path> FileAbstract::collectFiles(const std::function<std::vector<std::filesystem::path>(
															  		const std::filesystem::path& dir, 
															  		const std::vector<std::string_view>& ext)>& func)
{
	Log::console_log("Collecting files...");
	const auto files = func(m_dirPath, { m_fileTypes });
	
	Log::console_log(std::format("Collecting has been completed. Number of files: {}", files.size()));
	return files;
}