#include "FileTxt.hpp"
#include "getDirectoryFiles.hpp"
#include "getNotAllDirectoryFiles.hpp"

#include <iostream>
#include <fstream>
#include <memory>

FileTxt::FileTxt() { setFileType(".txt"); }
FileTxt::~FileTxt() {}

void FileTxt::findWordAll() {	
	std::string catalog, saveFileName, findingWord;
	int counterFile = 0;
	const std::filesystem::path path = enterPath();

	std::cout << "\nEnter a word to find: "; 
	std::cin >> findingWord; 
	setFindWord(std::move(findingWord));

	std::cout << "\nEnter the name of the file (example: C:\\somePath\\result.txt) where the result will be saved\n(No need to save the result - N): "; 
	std::cin >> saveFileName;

	FileAbstract::SaveFile fileToSave(std::move(saveFileName));
	
	auto print_result = [&counterFile, &fileToSave](const auto& files, const std::string& findWord) {
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
						
						if (fileToSave.getFileName() != "N") { 
							fileToSave.saveInfoTxt(findWord, currentFile, lineCounter, line, fileToSave.getFileName()); 
						}
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

	const auto files = getDirectoryFiles(path, { getFileType() });
	print_result(files, getFindWord());
}

void FileTxt::findWordNotAll() {
	std::string catalog, saveFileName, findingWord;
	int counterFile = 0;
	const std::filesystem::path path = enterPath();

	std::cout << "\nEnter a word to find: "; 
	std::cin >> findingWord; 
	setFindWord(findingWord);

	std::cout << "\nEnter the name of the file (example: C:\\somePath\\result.txt) where the result will be saved\n(No need to save the result - N): "; 
	std::cin >> saveFileName; 

	FileAbstract::SaveFile fileToSave(std::move(saveFileName));

	
	const auto files = getNotAllDirectoryFiles(path, { getFileType() });
	print_result(files, getFindWord());
}



