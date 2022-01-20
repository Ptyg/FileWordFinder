#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef CHRONO
#define CHRONO
#include <chrono>
#endif

#include "FileHtml.h"
#include "getDirectoryFiles.h"
#include "getNotAllDirectoryFiles.h"

void FileHtml::setFindWord(std::string& word) { _word = word; }
std::string FileHtml::getFindWord() { return _word; }

void FileHtml::displayFiles() {
	system("cls");
	std::string catalog;
	auto path = fs::current_path();

	std::cout << "\nНаходимся в каталоге: " << path;
	printf("\nВведите путь к каталогу\n(Внимание! Путь должен написан без использования символов кириллицы)\n(Если оставить как есть - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector)
			std::cout << f << "\n";
		std::cout << "\nКол-во файлов: " << aVector.size();
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getDirectoryFiles(path, { getFileType() });
	print_files(files);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	std::cout << "\nВремя: " << finalTime.count();
}
void FileHtml::displayNotAllFiles() {
	system("cls");
	std::string catalog;
	auto path = fs::current_path();

	std::cout << "\nНаходимся в каталоге: " << path;
	printf("\nВведите путь к каталогу\n(Внимание! Путь должен написан без использования символов кириллицы)\n(Если оставить как есть - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector)
			std::cout << f << "\n";
		std::cout << "\nКол-во файлов: " << aVector.size();
	};

	auto files = getNotAllDirectoryFiles(path, { getFileType() });
	print_files(files);
}

// TODO: это только в идз. Нужно убрать и заменить на поиск обьекта(?)
//void FileHtml::find3LefRightWords() {
//	system("cls");
//	FileAbstract::SaveFile obj;
//	string catalog, saveFileName;
//	int counterFile = 0;
//	auto path = fs::current_path(); //path = path / "TEST";
//
//	std::cout << "\nНаходимся в каталоге: " << path;
//
//	printf("\nВведите путь к каталогу\n(Внимание! Путь должен написан без использования символов кириллицы)\n(Если оставить как есть - D): "); std::cin >> catalog;
//	if (catalog != "D") { path = fs::path(catalog); }
//	std::cout << "\nВведите слово для поиска: "; std::cin >> _word;
//	cout << "\nВведите файл (пример: C:\\somePath\\result.txt), где будет сохранен результат\n(Если не нужно сохранять - N): "; cin >> saveFileName; obj._fileName = saveFileName;
//
//	auto print_result = [](const auto& aVector, const string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {
//		for (auto& f : aVector) {
//			ifstream file;
//			string line;
//			int counter = 1;
//
//			try {
//				file.open(f);
//				while (getline(file, line)) {
//					if (line.find(fWord) != string::npos) {
//						string lineTemp = line;
//						string tag, tagEnd;
//
//						for (int i = 0; i < lineTemp.size(); i++) {
//							if (lineTemp[i] == ' ') { continue; }
//							else {
//								if (line[i] == '>') {
//									tag.push_back(line[i]);
//									break;
//								}
//								tag.push_back(line[i]);
//							}
//						}
//						tagEnd = tag;
//						tagEnd.insert(1, "/");
//
//						int spaceBarCounter = 0, coun = 0;
//						while (lineTemp[coun] == ' ') { spaceBarCounter++; coun++; }
//						lineTemp.erase(0, spaceBarCounter);
//						line.erase(0, spaceBarCounter);
//
//						auto n = lineTemp.find(tag);
//						if (n != std::string::npos) { lineTemp.erase(n, tag.size()); }
//						auto n2 = lineTemp.find(tagEnd);
//						if (n2 != std::string::npos) { lineTemp.erase(n2, tagEnd.size()); }
//
//						vector<string> words;
//						string word;
//						int counterWords = 0;
//						int posWord = lineTemp.find(fWord), pos2Word = posWord;
//						while (lineTemp[pos2Word] != ' ') { pos2Word++; }
//
//						// in right
//						for (int i = pos2Word + 1; i <= lineTemp.size(); i++) {
//							if (counterWords < 3) {
//								if (i == lineTemp.size()) { words.push_back(word); word.clear(); counterWords++; }
//								else if (lineTemp[i] != ' ') { word.push_back(lineTemp[i]); }
//								else { words.push_back(word); word.clear(); counterWords++; }
//							}
//						}
//						// in left
//						counterWords = 0;
//						for (int i = posWord - 2; i >= 0; i--) {
//							if (counterWords < 3) {
//								if (i == 0) { word.push_back(lineTemp[i]); reverse(word.begin(), word.end()); words.push_back(word); word.clear(); counterWords++; }
//								else if (lineTemp[i] != ' ') { word.push_back(lineTemp[i]); }
//								else { reverse(word.begin(), word.end()); words.push_back(word); word.clear(); counterWords++; }
//							}
//						}
//
//						std::cout << "\nСлова по 3 шт-ки слева и справа: ";
//						for (int i = 0; i < words.size(); i++) {
//							if (words[i] != fWord) { std::cout << words[i] << " "; }
//						}
//						std::cout << "\nПуть: " << f;
//						std::cout << "\nНомер строки: " << counter;
//						std::cout << "\nСтрока: " << line;
//
//						counterFile++;
//						printf("\n\n");
//
//						
//						if (obj._fileName != "N") { obj.saveInfoHtml(words, f, counter, line, obj); }
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
//	auto files = getDirectoryFiles(path, { _fileType });
//	print_result(files, _word, counterFile, obj);
//
//	auto end = std::chrono::steady_clock::now();
//	std::chrono::duration<double> finalTime = end - start;
//	cout << "Кол-во файлов со схожим результатом поиска: " << counterFile;
//	cout << "\nВремя: " << finalTime.count();
//}
//void FileHtml::findNotAll3LefRightWords() {
//	system("cls");
//	FileAbstract::SaveFile obj;
//	string catalog, saveFileName;
//	int counterFile = 0;
//	auto path = fs::current_path(); //path = path / "TEST";
//
//	cout << "\nНаходимся в каталоге: " << path;
//
//	printf("\nВведите путь к каталогу\n(Внимание! Путь должен написан без использования символов кириллицы)\n(Если оставить как есть - D): "); std::cin >> catalog;
//	if (catalog != "D") { path = fs::path(catalog); }
//	cout << "\nВведите слово для поиска: "; cin >> _word;
//	cout << "\nВведите файл (пример: C:\\somePath\\result.txt), где будет сохранен результат\n(Если не нужно сохранять - N): "; cin >> saveFileName; obj._fileName = saveFileName;
//
//	auto print_result = [](const auto& aVector, const string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {
//		for (auto& f : aVector) {
//			ifstream file;
//			string line;
//			int counter = 1;
//
//			try {
//				file.open(f);
//				while (getline(file, line)) {
//					if (line.find(fWord) != string::npos) {
//						string lineTemp = line;
//						string tag, tagEnd;
//
//						for (int i = 0; i < lineTemp.size(); i++) {
//							if (lineTemp[i] == ' ') { continue; }
//							else {
//								if (line[i] == '>') {
//									tag.push_back(line[i]);
//									break;
//								}
//								tag.push_back(line[i]);
//							}
//						}
//						tagEnd = tag;
//						tagEnd.insert(1, "/");
//
//						int spaceBarCounter = 0, coun = 0;
//						while (lineTemp[coun] == ' ') { spaceBarCounter++; coun++; }
//						lineTemp.erase(0, spaceBarCounter);
//						line.erase(0, spaceBarCounter);
//
//						auto n = lineTemp.find(tag);
//						if (n != std::string::npos) { lineTemp.erase(n, tag.size()); }
//						auto n2 = lineTemp.find(tagEnd);
//						if (n2 != std::string::npos) { lineTemp.erase(n2, tagEnd.size()); }
//
//						vector<string> words;
//						string word;
//						int counterWords = 0;
//						int posWord = lineTemp.find(fWord), pos2Word = posWord;
//						while (lineTemp[pos2Word] != ' ') { pos2Word++; }
//
//						// in right
//						for (int i = pos2Word + 1; i <= lineTemp.size(); i++) {
//							if (counterWords < 3) {
//								if (i == lineTemp.size()) { words.push_back(word); word.clear(); counterWords++; }
//								else if (lineTemp[i] != ' ') { word.push_back(lineTemp[i]); }
//								else { words.push_back(word); word.clear(); counterWords++; }
//							}
//						}
//						// in left
//						counterWords = 0;
//						for (int i = posWord - 2; i >= 0; i--) {
//							if (counterWords < 3) {
//								if (i == 0) { word.push_back(lineTemp[i]); reverse(word.begin(), word.end()); words.push_back(word); word.clear(); counterWords++; }
//								else if (lineTemp[i] != ' ') { word.push_back(lineTemp[i]); }
//								else { reverse(word.begin(), word.end()); words.push_back(word); word.clear(); counterWords++; }
//							}
//						}
//
//						std::cout << "\nСлова по 3 шт-ки слева и справа: ";
//						for (int i = 0; i < words.size(); i++) {
//							if (words[i] != fWord) { std::cout << words[i] << " "; }
//						}
//						std::cout << "\nПуть: " << f;
//						std::cout << "\nНомер строки: " << counter;
//						std::cout << "\nСтрока: " << line;
//
//						counterFile++;
//						printf("\n\n");
//
//
//						if (obj._fileName != "N") { obj.saveInfoHtml(words, f, counter, line, obj); }
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
//	auto files = getNotAllDirectoryFiles(path, { _fileType });
//	print_result(files, _word, counterFile, obj);
//
//	auto end = std::chrono::steady_clock::now();
//	std::chrono::duration<double> finalTime = end - start;
//	cout << "Кол-во файлов со схожим результатом поиска: " << counterFile;
//	cout << "\nВремя: " << finalTime.count();
//}

const std::string& FileHtml::getFileType() const { return _fileType; }