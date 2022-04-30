#include "FileTxt.hpp"
#include "getDirectoryFiles.hpp"
#include "getNotAllDirectoryFiles.hpp"

#include <iostream>
#include <memory>
#include <fstream>

FileTxt::FileTxt() { 
	setFileType(".txt"); 
}

FileTxt::FileTxt(const std::string& findingWord){
	setFileType(".txt");
	setFindWord(findingWord);
}

FileTxt::FileTxt(std::string&& findingWord){
	setFileType(".txt");
	setFindWord(std::move(findingWord));
}

void FileTxt::showResultsFromAllDirs() {	
	std::string catalog;
	int counterFile = 0;

	auto print_result = [&counterFile](const auto& files, const std::string& findWord) {
		for (const auto& currentFile : files) {
			std::ifstream file;
			std::string line;
			int lineCounter = 1;
			try {
				file.open(currentFile);
				while (getline(file, line)) {
					if (line.find(findWord) != std::string::npos) {

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);

						std::cout << "\nSearching word: " << findWord;
						std::cout << "\nPath to file: " << currentFile;
						std::cout << "\nLine number: " << lineCounter;
						std::cout << "\nLine: " << line;
						std::cout << "\n\n";
						counterFile++;
					}
					lineCounter++;
				}
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << "\n";
				file.close();
			}
			file.close();
		}

		if (0 == counterFile) { 
			std::cout << "No files in dir\n"; 
		}
		
		std::cout << "\n";
	};

	const auto files = getDirectoryFiles(getDirPath(), { getFileType() });
	print_result(files, getFindWord());
}

void FileTxt::showResultsFromNotAllDirs() {
	std::string catalog;
	int counterFile = 0;

	auto print_result = [&counterFile](const auto& files, const std::string& findWord) {
		for (const auto& currentFile : files) {
			std::ifstream file;
			std::string line;
			int lineCounter = 1;
			try {
				file.open(currentFile);
				while (getline(file, line)) {
					if (line.find(findWord) != std::string::npos) {

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);

						std::cout << "\nSearching word: " << findWord;
						std::cout << "\nPath to file: " << currentFile;
						std::cout << "\nLine number: " << lineCounter;
						std::cout << "\nLine: " << line;
						std::cout << "\n\n";
						counterFile++;
					}
					lineCounter++;
				}
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << "\n";
				file.close();
			}
			file.close();
		}

		if (0 == counterFile) { 
			std::cout << "No files in dir"; 
		}
		
		std::cout << "\n";
	};

	const auto files = getNotAllDirectoryFiles(getDirPath(), { getFileType() });
	print_result(files, getFindWord());
}



