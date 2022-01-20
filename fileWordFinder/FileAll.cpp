

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef FILESYSTEM
#define FILESYSTEM
#include <filesystem>
namespace fs = std::filesystem;
#endif

#include "FileAll.h"
#include "getDirectoryFiles.h"
#include "getNotAllDirectoryFiles.h"

void FileAll::displayFiles() {
	system("cls");
	std::string catalog;
	auto path = fs::current_path(); //path = path / "TEST";

	std::cout << "\nНаходимся в каталоге: " << path;
	printf("\nВведите путь к каталогу\n(Внимание! Путь должен написан без использования символов кириллицы)\n(Если оставить как есть - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector) { std::cout << f << "\n"; }
		std::cout << "\nКол-во файлов: " << aVector.size();
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getDirectoryFiles(path, {});
	print_files(files);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	std::cout << "\nВремя: " << finalTime.count();
}
void FileAll::displayNotAllFiles() {
	system("cls");
	std::string catalog;
	auto path = fs::current_path(); //path = path / "TEST";

	std::cout << "\nНаходимся в каталоге: " << path;
	printf("\nВведите путь к каталогу\n(Внимание! Путь должен написан без использования символов кириллицы)\n(Если оставить как есть - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector) { std::cout << f << "\n"; }
		std::cout << "\nКол-во файлов: " << aVector.size();
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getNotAllDirectoryFiles(path, {});
	print_files(files);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	std::cout << "\nВремя: " << finalTime.count();
}

void FileAll::findWordAll() {
	system("cls");
	FileAbstract::SaveFile obj;
	std::string catalog, saveFileName;
	int counterFile = 0;
	auto path = fs::current_path(); //path = path / "TEST";

	std::cout << "\nНаходимся в каталоге: " << path;

	printf("\nВведите путь к каталогу\n(Внимание! Путь должен написан без использования символов кириллицы)\n(Если оставить как есть - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }
	std::cout << "\nВведите слово для поиска: "; std::cin >> _word;
	std::cout << "\nВведите файл (пример: C:\\somePath\\result.txt), где будет сохранен результат\n(Если не нужно сохранять - N): "; std::cin >> saveFileName; obj._fileName = saveFileName;

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

						std::cout << "\nИскомое слово: " << fWord;
						std::cout << "\nПуть: " << f;
						std::cout << "\nНомер строки: " << counter;
						std::cout << "\nСтрока: " << line;
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
		printf("\n");
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getDirectoryFiles(path, {});
	print_result(files, _word, counterFile, obj);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	std::cout << "Кол-во файлов со схожим результатом поиска: " << counterFile;
	std::cout << "\nВремя: " << finalTime.count();
}
void FileAll::findWordNotAll() {
	system("cls");
	FileAbstract::SaveFile obj;
	std::string catalog, saveFileName;
	int counterFile = 0;
	auto path = fs::current_path();

	std::cout << "\nНаходимся в каталоге: " << path;

	printf("\nВведите путь к каталогу\n(Внимание! Путь должен написан без использования символов кириллицы)\n(Если оставить как есть - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }
	std::cout << "\nВведите слово для поиска: "; std::cin >> _word;
	std::cout << "\nВведите файл (пример: C:\\somePath\\result.txt), где будет сохранен результат\n(Если не нужно сохранять - N): "; std::cin >> saveFileName; obj._fileName = saveFileName;

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

						std::cout << "\nИскомое слово: " << fWord;
						std::cout << "\nПуть: " << f;
						std::cout << "\nНомер строки: " << counter;
						std::cout << "\nСтрока: " << line;
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
		printf("\n");
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getNotAllDirectoryFiles(path, {});
	print_result(files, _word, counterFile, obj);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	std::cout << "Кол-во файлов со схожим результатом поиска: " << counterFile;
	std::cout << "\nВремя: " << finalTime.count();
}