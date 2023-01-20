#include "FileTxt.hpp"
#include "getDirectoryFiles.hpp"
#include "getNotAllDirectoryFiles.hpp"
#include "Log.hpp"

#include <iostream>
#include <memory>
#include <fstream>

FileTxt::FileTxt(std::string_view findingWord, std::string_view path) {
	m_word = findingWord;
	m_fileTypes = { path };
	m_dirPath = path;
}

std::vector<OutResult> FileTxt::findWord(const std::function<std::vector<std::filesystem::path>(
										 const std::filesystem::path& dir, 
										 const std::vector<std::string_view>& ext)>& func){
	int counterFile = 0;
	std::vector<OutResult> results;

	auto doFinding = [&](const auto& files, std::string_view findWord) {
		for (const auto& currentFile : files) {
			std::ifstream file;
			std::string line;
			int lineCounter = 1;
			try {
				file.open(currentFile.string());
				while (getline(file, line)) {
					if (line.find(findWord) != std::string::npos) {

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);
						results.push_back(OutResult(findWord.data(), currentFile.string(), std::move(line), lineCounter));
						counterFile++;
					}
					lineCounter++;
				}
			}
			catch (const std::exception& ex) {
				Log::console_log(ex.what(), "[ERROR]");
				file.close();
			}
			file.close();
		}

		if (0 == counterFile) {
			Log::console_log("No files with this word");
		}
		
		std::cout << "\n";
	};
	
	const auto files = collectFiles(func);
	
	Log::console_log("Finding word...");
	doFinding(files, m_word);

	return results;
}

