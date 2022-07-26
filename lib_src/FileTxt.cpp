#include "FileTxt.hpp"
#include "Timer.hpp"

#include <iostream>
#include <memory>
#include <fstream>

FileTxt::FileTxt(const std::filesystem::path& path, const std::string& findingWord /* = " " */){
	_extention = ".txt";
	_path = path;
	_word = findingWord;
}

FileTxt::FileTxt(std::filesystem::path&& path, std::string&& findingWord /* = " " */){
	_extention = ".txt"; 
	_path = std::move(path);
	_word = std::move(findingWord);
}

std::vector<OutResult> FileTxt::findWord(bool collect_recursivly /* = false */){
	int counterFile = 0;
	std::vector<OutResult> results;

	auto doFinding = [&](const auto& files, const std::string& findWord) {
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
						results.push_back(OutResult(findWord, currentFile, line, lineCounter));
						counterFile++;
					}
					lineCounter++;
				}
			}
			catch (const std::exception& ex) {
				std::cout << "[ERROR]: " << ex.what() << "\n";
				file.close();
			}
			file.close();
		}

		if (0 == counterFile) { 
			std::cout << "[INFO]: No files with this word"; 
		}
		
		std::cout << "\n";
	};
	
	const auto files = getDirectoryFiles(collect_recursivly);
	
	std::cout << "[INFO]: Finding word...\n";
	
#define DO_TIMER_FILE_TXT_FIND_WORD 1
#if DO_TIMER_FILE_TXT_FIND_WORD
	Timer t("Filexml::findObject");
#endif
	doFinding(files, _word);

	return results;
}



