#include "task.h"

void FileTxt::setFindWord(string& word) { _word = word; }
string FileTxt::getFindWord() { return _word; }

void FileTxt::displayFiles() {
	system("cls");
	string catalog;
	auto path = fs::current_path(); //path = path / "TEST";

	cout << "\nНаходимся в каталоге: " << path;
	printf("\nВведите путь к каталогу\n(Внимание! Путь должен написан без использования символов кириллицы)\n(Если оставить как есть - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector)
			cout << f << "\n";
		cout << "\nКол-во файлов: " << aVector.size();
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getDirectoryFiles(path, { _fileType });
	print_files(files);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	cout << "\nВремя: " << finalTime.count();
}
void FileTxt::displayNotAllFiles() {
	system("cls");
	string catalog;
	auto path = fs::current_path(); //path = path / "TEST";

	cout << "\nНаходимся в каталоге: " << path;
	printf("\nВведите путь к каталогу\n(Внимание! Путь должен написан без использования символов кириллицы)\n(Если оставить как есть - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector)
			cout << f << "\n";
		cout << "\nКол-во файлов: " << aVector.size();
	};

	auto files = getNotAllDirectoryFiles(path, { _fileType });
	print_files(files);
}

void FileTxt::findWordAll() {
	system("cls");
	FileAbstract::SaveFile obj;
	string catalog, saveFileName;
	int counterFile = 0;
	auto path = fs::current_path(); //path = path / "TEST";

	cout << "\nНаходимся в каталоге: " << path;
	
	printf("\nВведите путь к каталогу\n(Внимание! Путь должен написан без использования символов кириллицы)\n(Если оставить как есть - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }
	cout << "\nВведите слово для поиска: "; cin >> _word;
	cout << "\nВведите файл (пример: C:\\somePath\\result.txt), где будет сохранен результат\n(Если не нужно сохранять - N): "; cin >> saveFileName; obj._fileName = saveFileName;
	
	auto print_result = [](const auto& aVector, const string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {

		for (auto& f : aVector) {
			ifstream file;
			string line;
			int counter = 1;
			try {
				file.open(f);
				while (getline(file, line)) {
					if (line.find(fWord) != string::npos) {

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);

						cout << "\nИскомое слово: " << fWord;
						cout << "\nПуть: " << f;
						cout << "\nНомер строки: " << counter;
						cout << "\nСтрока: " << line;
						counterFile++;
						printf("\n\n");
						
						if (obj._fileName != "N") { obj.saveInfo(fWord, f, counter, line, obj); }
					}
					counter++;
				}
			}
			catch (const std::exception& ex) {
				cout << ex.what() << "\n";
				file.close();
			}
			file.close();
		}
		printf("\n");
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getDirectoryFiles(path, { _fileType });
	print_result(files, _word, counterFile, obj);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	cout << "Кол-во файлов со схожим результатом поиска: " << counterFile;
	cout << "\nВремя: " << finalTime.count();
}
void FileTxt::findWordNotAll() {
	system("cls");
	FileAbstract::SaveFile obj;
	string catalog, saveFileName;
	int counterFile = 0;
	auto path = fs::current_path(); //path = path / "TEST";

	cout << "\nНаходимся в каталоге: " << path;

	printf("\nВведите путь к каталогу\n(Внимание! Путь должен написан без использования символов кириллицы)\n(Если оставить как есть - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }
	cout << "\nВведите слово для поиска: "; cin >> _word;
	cout << "\nВведите файл (пример: C:\\somePath\\result.txt), где будет сохранен результат\n(Если не нужно сохранять - N): "; cin >> saveFileName; obj._fileName = saveFileName;

	auto print_result = [](const auto& aVector, const string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {

		for (auto& f : aVector) {
			ifstream file;
			string line;
			int counter = 1;
			try {
				file.open(f);
				while (getline(file, line)) {
					if (line.find(fWord) != string::npos) {

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);

						cout << "\nИскомое слово: " << fWord;
						cout << "\nПуть: " << f;
						cout << "\nНомер строки: " << counter;
						cout << "\nСтрока: " << line;
						counterFile++;
						printf("\n\n");

						if (obj._fileName != "N") { obj.saveInfo(fWord, f, counter, line, obj); }
					}
					counter++;
				}
			}
			catch (const std::exception& ex) {
				cout << ex.what() << "\n";
				file.close();
			}
			file.close();
		}
		printf("\n");
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getNotAllDirectoryFiles(path, { _fileType });
	print_result(files, _word, counterFile, obj);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	cout << "Кол-во файлов со схожим результатом поиска: " << counterFile;
	cout << "\nВремя: " << finalTime.count();
}

