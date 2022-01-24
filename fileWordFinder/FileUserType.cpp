//#ifndef IOSTREAM
//#define IOSTREAM
//#include <iostream>
//#endif
//
//#ifndef STRING
//#define STRING
//#include <string>
//#endif
//
//#ifndef FSTREAM
//#define FSTREAM
//#include <fstream>
//#endif
//
//#ifndef FILESYSTEM
//#define FILESYSTEM
//#include <filesystem>
//namespace fs = std::filesystem;
//#endif
//
//#include "FileUserType.h"
//#include "getDirectoryFiles.h"
//#include "getNotAllDirectoryFiles.h"
//
//void FileUserType::findWord() {
//	system("cls");
//	FileAbstract::SaveFile obj;
//	std::string catalog, saveFileName;
//	int counterFile = 0;
//	auto path = fs::current_path();
//
//	std::cout << "\nCurrent path: " << path;
//
//	printf("\nEnter path to the dir\n(Attention! The path must be written without using Cyrillic characters)\n(If left as is - D): "); std::cin >> catalog;
//	if (catalog != "D") { path = fs::path(catalog); }
//	std::cout << "\nEnter a word to find: "; std::cin >> _word;
//	std::cout << "\nEnter the name of the file (example: C:\\somePath\\result.txt) where the result will be saved\n(No need to save the result - N): "; std::cin >> saveFileName; obj._fileName = saveFileName;
//
//	auto print_result = [](const auto& aVector, const std::string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {
//
//		for (auto& f : aVector) {
//			std::ifstream file;
//			std::string line;
//			int counter = 1;
//			try {
//				file.open(f);
//				while (getline(file, line)) {
//					if (line.find(fWord) != std::string::npos) {
//
//						int spaceBarCounter = 0, coun = 0;
//						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
//						line.erase(0, spaceBarCounter);
//
//						std::cout << "\nSearching word: " << fWord;
//						std::cout << "\nPath to file: " << f;
//						std::cout << "\nLine number: " << counter;
//						std::cout << "\nLine: " << line;
//						counterFile++;
//						printf("\n\n");
//
//						if (obj._fileName != "N") { obj.saveInfoTxt(fWord, f, counter, line, obj); }
//					}
//					counter++;
//				}
//			}
//			catch (const std::exception& ex) {
//				std::cout << ex.what() << "\n";
//				file.close();
//			}
//			file.close();
//		}
//		printf("\n");
//	};
//
//	auto start = std::chrono::steady_clock::now();
//
//	auto files = getDirectoryFiles(path, { getFileType() });
//	print_result(files, _word, counterFile, obj);
//
//	auto end = std::chrono::steady_clock::now();
//	std::chrono::duration<double> finalTime = end - start;
//	std::cout << "Number of files with a similar search result: " << counterFile;
//	std::cout << "\nTime: " << finalTime.count();
//}
//void FileUserType::findWordNotAll() {
//	system("cls");
//	FileAbstract::SaveFile obj;
//	std::string catalog, saveFileName;
//	int counterFile = 0;
//	auto path = fs::current_path();
//
//	std::cout << "\nCurrent path: " << path;
//
//	printf("\nEnter path to the dir\n(Attention! The path must be written without using Cyrillic characters)\n(If left as is - D): "); std::cin >> catalog;
//	if (catalog != "D") { path = fs::path(catalog); }
//	std::cout << "\nEnter a word to find: "; std::cin >> _word;
//	std::cout << "\nEnter the name of the file (example: C:\\somePath\\result.txt) where the result will be saved\n(No need to save the result - N): "; std::cin >> saveFileName; obj._fileName = saveFileName;
//
//	auto print_result = [](const auto& aVector, const std::string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {
//
//		for (auto& f : aVector) {
//			std::ifstream file;
//			std::string line;
//			int counter = 1;
//			try {
//				file.open(f);
//				while (getline(file, line)) {
//					if (line.find(fWord) != std::string::npos) {
//
//						int spaceBarCounter = 0, coun = 0;
//						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
//						line.erase(0, spaceBarCounter);
//
//						std::cout << "\nSearching word: " << fWord;
//						std::cout << "\nPath to file: " << f;
//						std::cout << "\nLine number: " << counter;
//						std::cout << "\nLine: " << line;
//						counterFile++;
//						printf("\n\n");
//
//						if (obj._fileName != "N") { obj.saveInfoTxt(fWord, f, counter, line, obj); }
//					}
//					counter++;
//				}
//			}
//			catch (const std::exception& ex) {
//				std::cout << ex.what() << "\n";
//				file.close();
//			}
//			file.close();
//		}
//		printf("\n");
//	};
//
//	auto start = std::chrono::steady_clock::now();
//
//	auto files = getNotAllDirectoryFiles(path, { getFileType() });
//	print_result(files, _word, counterFile, obj);
//
//	auto end = std::chrono::steady_clock::now();
//	std::chrono::duration<double> finalTime = end - start;
//	std::cout << "Number of files with a similar search result: " << counterFile;
//	std::cout << "\nTime: " << finalTime.count();
//}