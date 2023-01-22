#include "FileTxt.hpp"
#include "Log.hpp"
#include "getDirectoryFiles.hpp"

#include <iostream>
#include <memory>
#include <fstream>

FileTxt::FileTxt(std::string_view findingWord, std::string_view path) {
	m_word = findingWord;
	m_fileTypes = { ".txt" };
	m_dirPath = path;
}

template<typename iterator>
std::vector<OutResult> FileTxt::findWord() {
	const auto files = getDirectoryFiles<iterator>(m_dirPath, m_fileTypes);

	Log::console_log("Finding word...");

	int counterFile = 0;
	std::vector<OutResult> results;

	for (const auto& currentFile : files) {
		std::ifstream file;
		std::string line;
		int lineCounter = 0;

		try {
			file.open(currentFile.string());
			while (getline(file, line)) {
				if (line.find(m_word) != std::string::npos) {
					int spaceBarCounter = 0, count = 0;
					while (line[count] == ' ') { spaceBarCounter++; count++; }
					line.erase(0, spaceBarCounter);
					results.push_back(OutResult(m_word.data(), currentFile.string(), std::move(line), lineCounter));
					counterFile++;
				}
				lineCounter++;
			}
		}
		catch (const std::exception& ex) {
			Log::console_log(ex.what(), "[ERROR]");
		}
		file.close();
	}

	if (0 == counterFile) {
		Log::console_log("No files with this word");
	}

	return results;
}
