#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif


#ifndef CHRONO
#define CHRONO
#include <chrono>
#endif

#ifndef FILESYSTEM
#define FILESYSTEM
#include <filesystem>
namespace fs = std::filesystem;
#endif

#include "FileXml.h"
#include "getDirectoryFiles.h"
#include "getNotAllDirectoryFiles.h"

FileXml::FileXml() { setFileType(".xml"); }
FileXml::~FileXml() {}
void FileXml::findWordAll() {
	system("cls");
	FileAbstract::SaveFile obj;
	std::string catalog, saveFileName, findingWord;
	int counterFile = 0;
	auto path = fs::current_path();

	std::cout << "\nCurrent path: " << path;
	printf("\nEnter path to the dir\n(Attention! The path must be written without using Cyrillic characters)\n \
		(If left as is - D): ");
	std::cin >> catalog;

	if (catalog != "D") { path = fs::path(catalog); }

	std::cout << "\nEnter a word to find: "; std::cin >> findingWord; setFindWord(findingWord);
	std::cout << "\nEnter the name of the file (example: C:\\somePath\\result.txt) where the result will be saved\n(No need to save the result - N): "; std::cin >> saveFileName; obj._fileName = saveFileName;

	auto spaceBarEraserFromFront = [](std::string& line) {
		int spaceBarCounter = 0, coun = 0;
		while (line[coun] == ' ' && coun < line.size()) { spaceBarCounter++; coun++; }
		line.erase(0, spaceBarCounter);
	};

	auto deleteExtraObjects = [](std::vector<std::string>& obj) {
		const char SLASH = '/';

		// i - obj with slash, j - without slash
		for (int i = 0; i < obj.size(); i++) {
			if (obj[i][1] == SLASH) {
				std::string tmp = obj[i];
				tmp.erase(remove(tmp.begin(), tmp.end(), SLASH), tmp.end());
				for (int j = i - 1; j >= 0; j--) {
					if (obj[j] == tmp) { obj.erase(obj.begin() + i); obj.erase(obj.begin() + j); }
					break;
				}
			}
		}
	};

	auto print_result = [&spaceBarEraserFromFront, &deleteExtraObjects](const auto& aVector, const std::string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {
		for (auto& f : aVector) {
			std::ifstream file;
			std::string line;
			std::vector <std::string> objects;
			const char FIRST_BRACKET = '<', SECOND_BRACKET = '>';
			int counter = 1;

			try {
				file.open(f);
				while (getline(file, line)) {

					int forstObjectBracketPos = line.find(FIRST_BRACKET);
					int secondObjectBracketPos = line.find(SECOND_BRACKET);
					int objectWordLengthWithBracket = secondObjectBracketPos - forstObjectBracketPos;
					spaceBarEraserFromFront(line);

					if (objectWordLengthWithBracket < line.size() - 1) {
						if (line.find(fWord) != std::string::npos) {
							std::string tag;

							spaceBarEraserFromFront(line);

							for (int i = 0; i < line.size(); i++) {
								if (line[i] == ' ') { continue; }
								else {
									if (line[i] == '>') {
										tag.push_back(line[i]);
										break;
									}
									tag.push_back(line[i]);
								}
							}

							deleteExtraObjects(objects);

							std::cout << "\nObject path: "; 
							for (auto& obj : objects) { std::cout << obj << ' '; }
							std::cout << "\nWords` tag: " << tag;
							for (size_t i = 0; i < tag.size(); i++) {
								if (tag[i] == '<') { tag.insert(i + 1, std::string("/")); break; }
							}
							std::cout << tag;
							std::cout << "\nFiles` path: " << f;
							std::cout << "\nLine number: " << counter;
							std::cout << "\nLine: " << line;
							counterFile++;
							printf("\n\n");

							if (obj._fileName != "N") { obj.saveInfoXml(tag, f, counter, line, obj, objects); }
						}
					}
					else { objects.push_back(line); }
					counter++;
				}
			}
			catch (const std::exception& ex) {
				printf("\nFile does not exist\n");
				std::cout << ex.what() << "\n";
				file.close();
			}

			file.close();
		}
		printf("\n");
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getDirectoryFiles(path, { getFileType() });
	print_result(files, getFindWord(), counterFile, obj);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	std::cout << "Number of files with a similar search result: " << counterFile;
	std::cout << "\nTime: " << finalTime.count();
}
void FileXml::findWordNotAll() {
	system("cls");
	FileAbstract::SaveFile obj;
	std::string catalog, saveFileName, findingWord;
	int counterFile = 0;
	auto path = fs::current_path();

	std::cout << "\nCurrent path: " << path;
	printf("\nEnter path to the dir\n(Attention! The path must be written without using Cyrillic characters)\n \
		(If left as is - D): ");
	std::cin >> catalog;

	if (catalog != "D") { path = fs::path(catalog); }

	std::cout << "\nEnter a word to find: "; std::cin >> findingWord; setFindWord(findingWord);
	std::cout << "\nEnter the name of the file (example: C:\\somePath\\result.txt) where the result will be saved\n \
					(No need to save the result  - N): "; 
	std::cin >> saveFileName; obj._fileName = saveFileName;

	auto spaceBarEraserFromFront = [](std::string& line) {
		int spaceBarCounter = 0, coun = 0;
		while (line[coun] == ' ' && coun < line.size()) { spaceBarCounter++; coun++; }
		line.erase(0, spaceBarCounter);
	};

	auto deleteExtraObjects = [](std::vector<std::string>& obj) {
		const char SLASH = '/';

		// i - obj with slash, j - without slash
		for (int i = 0; i < obj.size(); i++) {
			if (obj[i][1] == SLASH) {
				std::string tmp = obj[i];
				tmp.erase(remove(tmp.begin(), tmp.end(), SLASH), tmp.end());
				for (int j = i - 1; j >= 0; j--) {
					if (obj[j] == tmp) { obj.erase(obj.begin() + i); obj.erase(obj.begin() + j); }
					break;
				}
			}
		}
	};

	auto print_result = [&spaceBarEraserFromFront, &deleteExtraObjects](const auto& aVector, const std::string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {
		for (auto& f : aVector) {
			std::ifstream file;
			std::string line;
			std::vector <std::string> objects;
			const char FIRST_BRACKET = '<', SECOND_BRACKET = '>';
			int counter = 1;

			try {
				file.open(f);
				while (getline(file, line)) {

					int forstObjectBracketPos = line.find(FIRST_BRACKET);
					int secondObjectBracketPos = line.find(SECOND_BRACKET);
					int objectWordLengthWithBracket = secondObjectBracketPos - forstObjectBracketPos;
					spaceBarEraserFromFront(line);

					if (objectWordLengthWithBracket < line.size() - 1) {
						if (line.find(fWord) != std::string::npos) {
							std::string tag;

							spaceBarEraserFromFront(line);

							for (int i = 0; i < line.size(); i++) {
								if (line[i] == ' ') { continue; }
								else {
									if (line[i] == '>') {
										tag.push_back(line[i]);
										break;
									}
									tag.push_back(line[i]);
								}
							}

							deleteExtraObjects(objects);

							std::cout << "\nObject path: ";
							for (auto& obj : objects) { std::cout << obj << ' '; }
							std::cout << "\nWords` tag: " << tag;
							for (size_t i = 0; i < tag.size(); i++) {
								if (tag[i] == '<') { tag.insert(i + 1, std::string("/")); break; }
							}
							std::cout << tag;
							std::cout << "\nFiles` path: " << f;
							std::cout << "\nLine number: " << counter;
							std::cout << "\nLine: " << line;
							counterFile++;
							printf("\n\n");

							if (obj._fileName != "N") { obj.saveInfoXml(tag, f, counter, line, obj, objects); }
						}
					}
					else { objects.push_back(line); }
					counter++;
				}
			}
			catch (const std::exception& ex) {
				printf("\nFile does not exist\n");
				std::cout << ex.what() << "\n";
				file.close();
			}

			file.close();
		}
		printf("\n");
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getNotAllDirectoryFiles(path, { getFileType() });
	print_result(files, getFindWord(), counterFile, obj);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	std::cout << "Кол-во файлов со схожим результатом поиска: " << counterFile;
	std::cout << "\nВремя: " << finalTime.count();
}