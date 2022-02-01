#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif

#include "FileXml.h"
#include "getDirectoryFiles.h"
#include "getNotAllDirectoryFiles.h"

FileXml::FileXml() { setFileType(".xml"); }
FileXml::~FileXml() {}
void FileXml::findObject() {
	system("cls");
	FileAbstract::SaveFile obj;
	std::string catalog, saveFileName, findingWord;
	int counterFile = 0;
	const std::filesystem::path path = enterPath();

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
		for (int i = obj.size() - 1; i >= 0; i--) {
			if (obj[i][1] == SLASH) {
				std::string tmp = obj[i];
				tmp.erase(remove(tmp.begin(), tmp.end(), SLASH), tmp.end()); tmp.pop_back();
				int lenToCrop = tmp.size();
				
				//delete objects, finally
				for (int j = i - 1; j >= 0; j--) {
					if (obj[j].size() > lenToCrop) {
						std::string tmp2{ obj[j] };
						tmp2.erase(tmp2.begin()+lenToCrop, tmp2.end());

						if (tmp2 == tmp) { obj.erase(obj.begin() + i); obj.erase(obj.begin() + j); }
						break;
					}
					
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
							std::cout << "\nWord`s tag: " << tag;
							for (size_t i = 0; i < tag.size(); i++) {
								if (tag[i] == '<') { tag.insert(i + 1, std::string("/")); break; }
							}
							std::cout << tag;
							std::cout << "\nFile`s path: " << f;
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

		if (0 == counterFile) { std::cout << "No files in dir"; }

		printf("\n");
	};

	auto files = getDirectoryFiles(path, { getFileType() });
	print_result(files, getFindWord(), counterFile, obj);
}
void FileXml::findNotAllObject() {
	system("cls");
	FileAbstract::SaveFile obj;
	std::string catalog, saveFileName, findingWord;
	int counterFile = 0;
	const std::filesystem::path path = enterPath();

	std::cout << "\nEnter a word to find: "; std::cin >> findingWord; setFindWord(findingWord);
	std::cout << "\nEnter the name of the file (example: C:\\somePath\\result.txt) where the result will be saved\n(No need to save the result  - N): "; 
	std::cin >> saveFileName; obj._fileName = saveFileName;

	auto spaceBarEraserFromFront = [](std::string& line) {
		int spaceBarCounter = 0, coun = 0;
		while (line[coun] == ' ' && coun < line.size()) { spaceBarCounter++; coun++; }
		line.erase(0, spaceBarCounter);
	};

	auto deleteExtraObjects = [](std::vector<std::string>& obj) {
		const char SLASH = '/';

		// i - obj with slash, j - without slash
		for (int i = obj.size() - 1; i >= 0; i--) {
			if (obj[i][1] == SLASH) {
				std::string tmp = obj[i];
				tmp.erase(remove(tmp.begin(), tmp.end(), SLASH), tmp.end()); tmp.pop_back();
				int lenToCrop = tmp.size();

				//delete objects, finally
				for (int j = i - 1; j >= 0; j--) {
					if (obj[j].size() > lenToCrop) {
						std::string tmp2{ obj[j] };
						tmp2.erase(tmp2.begin() + lenToCrop, tmp2.end());

						if (tmp2 == tmp) { obj.erase(obj.begin() + i); obj.erase(obj.begin() + j); }
						break;
					}

				}
			}
		}

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
							std::cout << "\nWord`s tag: " << tag;
							for (size_t i = 0; i < tag.size(); i++) {
								if (tag[i] == '<') { tag.insert(i + 1, std::string("/")); break; }
							}
							std::cout << tag;
							std::cout << "\nFile`s path: " << f;
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

		if (0 == counterFile) { std::cout << "No files in dir"; }

		printf("\n");
	};

	auto files = getNotAllDirectoryFiles(path, { getFileType() });
	print_result(files, getFindWord(), counterFile, obj);
}