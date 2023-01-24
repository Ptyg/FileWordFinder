#ifndef FILE_TXT_H
#define FILE_TXT_H

#include "FileAbstract.hpp"
#include "outResultBase.hpp"
#include "Log.hpp"

#include <fstream>

class FileTxt : public FileAbstract {
public:
	FileTxt(std::string_view findingWord, std::string_view path);

	template<typename iterator = std::filesystem::directory_iterator>
	std::vector<OutResult> findWord() {
		const auto files = getDirectoryFiles<iterator>(m_dirPath, m_fileTypes);

		log::console_log("Finding word...", "[INFO]");

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
				log::console_log(ex.what(), "[ERROR]");
			}
			file.close();
		}

		if (0 == counterFile) {
			log::console_log("No files with this word", "[INFO]");
		}

		return results;
	}
};

#endif
