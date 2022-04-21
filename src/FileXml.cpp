#include "FileXml.hpp"
#include "getDirectoryFiles.hpp"
#include "getNotAllDirectoryFiles.hpp"

#include <iostream>
#include <fstream>
#include <memory>

FileXml::FileXml() { 
	setFileType(".xml"); 
}

FileXml::FileXml(const std::string& findingWord){
	setFileType(".xml"); 
	setFindWord(findingWord);
}

FileXml::FileXml(std::string&& findingWord){
	setFileType(".xml");
	setFindWord(std::move(findingWord));
}
	
void FileXml::showResultsFromAllDirs() {
	std::string catalog;
	int counterFile = 0;

	auto spaceBarEraserFromFront = [](std::string& line) {
		int spaceBarCounter = 0, count = 0;
		while (line[count] == ' ' && count < line.size()) { 
			spaceBarCounter++; 
			count++; 
		}
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
	};

	auto print_result = [&](const auto& files, const std::string& findingWord) {
		for (const auto& currentFile : files) {
			std::ifstream file;
			std::string line;
			std::vector<std::string> objects;
			const char FIRST_BRACKET = '<', SECOND_BRACKET = '>';
			int counter = 1;

			try {
				file.open(currentFile);
				while (getline(file, line)) {

					int forstObjectBracketPos = line.find(FIRST_BRACKET);
					int secondObjectBracketPos = line.find(SECOND_BRACKET);
					int objectWordLengthWithBracket = secondObjectBracketPos - forstObjectBracketPos;
					spaceBarEraserFromFront(line);

					if (objectWordLengthWithBracket < line.size() - 1) {
						if (line.find(findingWord) != std::string::npos) {
							std::string tag;

							spaceBarEraserFromFront(line);

							for (int i = 0; i < line.size(); i++) {
								if (line[i] == ' ') { 
									continue; 
								}
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
							for (const auto& obj : objects) { 
								std::cout << obj << ' '; 
							}

							std::cout << "\nWord`s tag: " << tag;
							for (size_t i = 0; i < tag.size(); i++) {
								if (tag[i] == '<') { 
									tag.insert(i + 1, std::string("/")); 
									break; 
								}
							}

							std::cout << tag;
							std::cout << "\nFile`s path: " << currentFile;
							std::cout << "\nLine number: " << counter;
							std::cout << "\nLine: " << line;
							counterFile++;
							std::cout << "\n\n";
						}
					}
					else { 
						objects.push_back(line); 	
					}
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

		if (0 == counterFile) { 
			std::cout << "No files in dir"; 
		}
		std::cout << "\n";
	};

	const auto files = getDirectoryFiles(getDirPath(), { getFileType() });
	print_result(files, getFindWord());
}

void FileXml::showResultsFromNotAllDirs() {
	std::string catalog;
	int counterFile = 0;

	auto spaceBarEraserFromFront = [](std::string& line) {
		int spaceBarCounter = 0, coun = 0;
		while (line[coun] == ' ' && coun < line.size()) { 
			spaceBarCounter++; coun++; 
		}
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

						if (tmp2 == tmp) { 
							obj.erase(obj.begin() + i); 
							obj.erase(obj.begin() + j); 
						}
						break;
					}
				}
			}
		}
	};

	auto print_result = [&](const auto& files, const std::string& findingWord) {
		for (auto& currentFile : files) {
			std::ifstream file;
			std::string line;
			std::vector <std::string> objects;
			const char FIRST_BRACKET = '<', SECOND_BRACKET = '>';
			int counter = 1;

			try {
				file.open(currentFile);
				while (getline(file, line)) {
					int forstObjectBracketPos = line.find(FIRST_BRACKET);
					int secondObjectBracketPos = line.find(SECOND_BRACKET);
					int objectWordLengthWithBracket = secondObjectBracketPos - forstObjectBracketPos;
					spaceBarEraserFromFront(line);

					if (objectWordLengthWithBracket < line.size() - 1) {
						if (line.find(findingWord) != std::string::npos) {
							std::string tag;

							spaceBarEraserFromFront(line);

							for (int i = 0; i < line.size(); i++) {
								if (line[i] == ' ') { 
									continue; 
								}
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
							for (const auto& obj : objects) { 
								std::cout << obj << ' '; 
							}
							
							std::cout << "\nWord`s tag: " << tag;
							for (size_t i = 0; i < tag.size(); i++) {
								if (tag[i] == '<') { 
									tag.insert(i + 1, std::string("/")); 
									break; 
								}
							}
							std::cout << tag;
							std::cout << "\nFile`s path: " << findingWord;
							std::cout << "\nLine number: " << counter;
							std::cout << "\nLine: " << line;
							counterFile++;
							std::cout << "\n\n";
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

		if (0 == counterFile) { 
			std::cout << "No files in dir"; 
		}
		std::cout << "\n";
	};

	const auto files = getNotAllDirectoryFiles(getDirPath(), { getFileType() });
	print_result(files, getFindWord());
}