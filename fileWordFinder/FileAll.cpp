#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif

#include "FileAll.h"
#include "getDirectoryFiles.h"
#include "getNotAllDirectoryFiles.h"

void FileAll::findWordAll() {
	system("cls");
	FileAbstract::SaveFile obj;
	std::string catalog, saveFileName, findingWord;
	int counterFile = 0;
	const std::filesystem::path path = enterPath();

	std::cout << "\nEnter a word to find: "; std::cin >> findingWord; 
	setFindWord(findingWord);
	std::cout << "\nEnter the name of the file (example: C:\\somePath\\result.txt) where the result will be saved\n(No need to save the result - N): "; std::cin >> saveFileName; obj._fileName = saveFileName;

	auto print_result = [](const auto& aVector, const std::string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {

		for (auto& f : aVector) {
			std::ifstream file;
			std::string line;
			int counter = 1;
			try {
				file.open(f);
				while (getline(file, line)) {
					if (line.find(fWord) != std::string::npos) {

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);

						std::cout << "\nSearching word: " << fWord;
						std::cout << "\nPath: " << f;
						std::cout << "\nLine number: " << counter;
						std::cout << "\nLine: " << line;
						counterFile++;
						printf("\n\n");

						if (obj._fileName != "N") { obj.saveInfoTxt(fWord, f, counter, line, obj); }
					}
					counter++;
				}
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << "\n";
				file.close();
			}
			file.close();
		}

		if (0 == counterFile) { std::cout << "No files in dir"; }

		printf("\n");
	};

	auto files = getDirectoryFiles(path, {});
	print_result(files, getFindWord(), counterFile, obj);
}
void FileAll::findWordNotAll() {
	system("cls");
	FileAbstract::SaveFile obj;
	std::string catalog, saveFileName, findingWord;
	int counterFile = 0;
	const std::filesystem::path path = enterPath();

	std::cout << "\nEnter a word to find: "; std::cin >> findingWord; 
	setFindWord(findingWord);
	std::cout << "\nEnter the name of the file (example: C:\\somePath\\result.txt) where the result will be saved\n(No need to save the result - N): "; 
	std::cin >> saveFileName; obj._fileName = saveFileName;

	auto print_result = [](const auto& aVector, const std::string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {

		for (auto& f : aVector) {
			std::ifstream file;
			std::string line;
			int counter = 1;
			try {
				file.open(f);
				while (getline(file, line)) {
					if (line.find(fWord) != std::string::npos) {

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);

						std::cout << "\nSearching word: " << fWord;
						std::cout << "\nPath: " << f;
						std::cout << "\nLine number: " << counter;
						std::cout << "\nLine: " << line;
						counterFile++;
						printf("\n\n");

						if (obj._fileName != "N") { obj.saveInfoTxt(fWord, f, counter, line, obj); }
					}
					counter++;
				}
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << "\n";
				file.close();
			}
			file.close();
		}

		if (0 == counterFile) { std::cout << "No files in dir"; }

		printf("\n");
	};

	auto files = getNotAllDirectoryFiles(path, {});
	print_result(files, getFindWord(), counterFile, obj);
}