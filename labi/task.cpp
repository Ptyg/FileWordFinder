#include "task.h"

vector<string> getDirectoryFiles(const fs::path& dir, const vector<string>& ext) {
	vector<string> files;
	try{
		for (auto& p : fs::recursive_directory_iterator(dir)) {
			if (fs::is_regular_file(p)) {
				if (ext.empty() || find(ext.begin(), ext.end(), p.path().extension().string()) != ext.end())
					files.push_back(p.path().string());
			}
		}
	}
	catch (const std::exception& ex){
		cout << ex.what() << "\n";
		cin.ignore(); cin.get();
	}
	
	return files;
}

vector<string> getNotAllDirectoryFiles(const fs::path& dir, const vector<string>& ext) {
	vector<string> files;
	try{
		for (auto& p : fs::directory_iterator(dir)) {
			if (fs::is_regular_file(p)) {
				if (ext.empty() || find(ext.begin(), ext.end(), p.path().extension().string()) != ext.end())
					files.push_back(p.path().string());
			}
		}
	}
	catch (const std::exception& ex){
		cout << ex.what() << "\n";
		cin.ignore(); cin.get();
	}
	
	return files;
}

vector<string> getDirectoryFilesNames(const fs::path& dir, const vector<string>& ext) {
	vector<string> files;
	for (auto& p : fs::directory_iterator(dir)) {
		if (fs::is_regular_file(p)) {
			if (ext.empty() || find(ext.begin(), ext.end(), p.path().extension().string()) != ext.end())
				files.push_back(p.path().filename().string());
		}
	}
	return files;
}

vector<string> getDirectoryNotAllFilesNames(const fs::path& dir, const vector<string>& ext) {
	vector<string> files;
	for (auto& p : fs::directory_iterator(dir)) {
		if (fs::is_regular_file(p)) {
			if (ext.empty() || find(ext.begin(), ext.end(), p.path().extension().string()) != ext.end())
				files.push_back(p.path().filename().string());
		}
	}
	return files;
}

//////////////////////////////////////////////////////
//
// ДЛЯ ФАЙЛОВ .TXT
//  
//////////////////////////////////////////////////////

// отображение всех txt с учетом всех дерикторий и без
void displayTxtFiles() {
	FileTxt* ftxt = new FileTxt();
	ftxt->displayFiles();
	delete ftxt;

	cin.ignore(); cin.get();
}
void displayNotAllTxtFiles() {
	FileTxt* ftxt = new FileTxt();
	ftxt->displayNotAllFiles();
	delete ftxt;

	cin.ignore(); cin.get();
}

// поиск слов в txt с учетом всех дерикторий и без
void findWord() {
	FileTxt* ftxt = new FileTxt();
	ftxt->findWordAll();
	delete ftxt;

	cin.ignore(); cin.get();
}
void findNotAllWord() {
	FileTxt* ftxt = new FileTxt();
	ftxt->findWordNotAll();
	delete ftxt;

	cin.ignore(); cin.get();
}

//////////////////////////////////////////////////////
//
// ДЛЯ ФАЙЛОВ .XML
//  
//////////////////////////////////////////////////////

// отображение всех xml с учетом всех дерикторий и без
void displayXmlFiles() {
	FileXml* fxml = new FileXml();
	fxml->displayFiles();
	delete fxml;

	cin.ignore(); cin.get();
}
void displayNotAllXmlFiles() {
	FileXml* fxml = new FileXml();
	fxml->displayNotAllFiles();
	delete fxml;

	cin.ignore(); cin.get();
}

// поиск объектов в xml с учетом всех дерикторий и без
void findObject() {
	FileXml* fxmp = new FileXml();
	fxmp->findWordAll();
	delete fxmp;

	cin.ignore(); cin.get();
}
void findNotAllObject(){
	FileXml* fxmp = new FileXml();
	fxmp->findWordNotAll();
	delete fxmp;

	cin.ignore(); cin.get();
}

//////////////////////////////////////////////////////
//
// ДЛЯ ФАЙЛОВ .HTML
//  
//////////////////////////////////////////////////////

// отображение всех html с учетом всех дерикторий и без
void displayHtmlFiles() {
	FileHtml* fhtml = new FileHtml();
	fhtml->displayFiles();
	delete fhtml;

	cin.ignore(); cin.get();
}
void displayNotAllHtmlFiles() {
	FileHtml* fhtml = new FileHtml();
	fhtml->displayNotAllFiles();
	delete fhtml;

	cin.ignore(); cin.get();
}

// поиск слов в html с учетом всех дерикторий и без
void find3Words() {
	FileHtml* fhtml = new FileHtml();
	fhtml->findNotAll3LefRightWords();
	delete fhtml;

	cin.ignore(); cin.get();
}
void findNotAll3Words() {
	FileHtml* fhtml = new FileHtml();
	fhtml->findNotAll3LefRightWords();
	delete fhtml;

	cin.ignore(); cin.get();
}

//////////////////////////////////////////////////////
//
// ДЛЯ ВСЕХ ТИПОВ ФАЙЛОВ
//  
//////////////////////////////////////////////////////

// отображение всех типов файлов с учетом всех дерикторий и без
void displayAllFiles() {
	FileAll* fAll = new FileAll();
	fAll->displayFiles();
	delete fAll;

	cin.ignore(); cin.get();
}
void displayNotAllFiles() {
	FileAll* fAll = new FileAll();
	fAll->displayNotAllFiles();
	delete fAll;

	cin.ignore(); cin.get();
}

// поиск слов во всех файлах с учетом всех дерикторий и без
void findWordAll() {
	FileAll* fAll = new FileAll();
	fAll->findWordAll();
	delete fAll;

	cin.ignore(); cin.get();
}
void findNotAllWordAll() {
	FileAll* fAll = new FileAll();
	fAll->findWordNotAll();
	delete fAll;

	cin.ignore(); cin.get();
}

//////////////////////////////////////////////////////
//
// ДЛЯ ПОЛЬЗОВАТЕЛЬСКИХ ТИПОВ ФАЙЛОВ
//  
//////////////////////////////////////////////////////

// отображение всех пользовательских типов файлов с учетом всех дерикторий и без
void displayAllUserFiles() {
	system("cls");
	FileUserType* fuft = new FileUserType();
	string fileType;

	cout << "Введите тип файла(Пример: .txt): "; cin >> fileType;
	fuft->setFileType(fileType);

	fuft->displayFiles();
	delete fuft;
	
	cin.ignore(); cin.get();
}
void displayNotAllUserFiles() {
	system("cls");
	FileUserType* fuft = new FileUserType();
	string fileType;

	cout << "Введите тип файла(Пример: .txt):: "; cin >> fileType;
	fuft->setFileType(fileType);
	fuft->displayNotAllFiles();

	delete fuft;

	cin.ignore(); cin.get();
}

// поиск слов в введном типе файла с учетом всех дерикторий и без
void findUserWord() {
	system("cls");
	FileUserType* fuft = new FileUserType();
	string fileType;

	cout << "Введите тип файла(Пример: .txt):: "; cin >> fileType;
	fuft->setFileType(fileType);
	fuft->findWord();

	delete fuft;

	cin.ignore(); cin.get();
}
void findNotAllUserWord() {
	system("cls");
	FileUserType* fuft = new FileUserType();
	string fileType;

	cout << "Введите тип файла(Пример: .txt):: "; cin >> fileType;
	fuft->setFileType(fileType);
	fuft->findWordNotAll();

	delete fuft;

	cin.ignore(); cin.get();
}

//////////////////////////////////////////////////////
//
// ИНТЕРФЕЙСЫ ДЛЯ КАЖДОГО ТИПА ФАЙЛА
//  
//////////////////////////////////////////////////////

void userInterfaceAll() {
	char ch;
	do {
		system("cls");
		printf("01. Отобразить все файлы в каталоге с учетом вложеных каталогов\n");
		printf("02. Отобразить все файлы в каталоге без учета вложеных каталогов\n");
		printf("03. Поиск слова во всех файлах c учетом вложеных каталогов\n");
		printf("04. Поиск слова во всех файлах без учета вложеных каталогов\n");
		printf("05. Выход\n");
		printf("Пожалуйста, введите число (1-5): "); cin >> ch;

		switch (ch) {
		case '1': displayAllFiles(); break;
		case '2': displayNotAllFiles(); break;
		case '3': findWordAll(); break;
		case '4': findNotAllWordAll(); break;
		case '5': break;

		default: printf("\a"); break;
		}
	} while (ch != '5');
}
void userInterfaceTxt() {
	char ch;
	do {
		system("cls");
		printf("01. Отобразить все файлы .txt с учетом вложеных каталогов\n");
		printf("02. Отобразить все файлы .txt без учета вложеных каталогов\n");
		printf("03. Поиск слова c учетом вложеных каталогов\n");
		printf("04. Поиск слова без учета вложеных каталогов\n");
		printf("05. Выход\n");
		printf("Пожалуйста, введите число (1-5): "); cin >> ch;

		switch (ch) {
		case '1': displayTxtFiles(); break;
		case '2': displayNotAllTxtFiles(); break;
		case '3': findWord(); break;
		case '4': findNotAllWord(); break;
		case '5': break;
		default: printf("\a"); break;
		}
	} while (ch != '5');
}
void userInterfaceXml() {
	char ch;
	do {
		system("cls");
		printf("01. Отобразить все файлы .xml с учетом вложеных каталогов\n");
		printf("02. Отобразить все файлы .xml без учета вложеных каталогов\n");
		printf("03. Поиск объекта c учетом вложеных каталогов\n");
		printf("04. Поиск объекта без учета вложеных каталогов\n");
		printf("05. Выход\n");
		printf("Пожалуйста, введите число (1-5): "); cin >> ch;

		switch (ch) {
		case '1': displayXmlFiles(); break;
		case '2': displayNotAllXmlFiles(); break;
		case '3': findObject(); break;
		case '4': findNotAllObject(); break;
		case '5': break;
		default: printf("\a"); break;
		}
	} while (ch != '5');
}
void userInterfaceHtml() {
	char ch;
	do {
		system("cls");
		printf("01. Отобразить все файлы .html с учетом вложеных каталогов\n");
		printf("02. Отобразить все файлы .html без учета вложеных каталогов\n");
		printf("03. Поиск 3-ех слов слева и справа c учетом вложеных каталогов\n");
		printf("04. Поиск 3-ех слов слева и справа без учета вложеных каталогов\n");
		printf("05. Выход\n");
		printf("Пожалуйста, введите число (1-5): "); cin >> ch;

		switch (ch) {
		case '1': displayHtmlFiles(); break;
		case '2': displayNotAllHtmlFiles(); break;
		case '3': find3Words(); break;
		case '4': findNotAll3Words(); break;
		case '5': break;

		default: printf("\a"); break;
		}
	} while (ch != '5');
}
void userInterfaceUserFileType() {
	char ch;
	do {
		system("cls");
		printf("01. Отобразить все файлы с веденным типом с учетом вложеных каталогов\n");
		printf("02. Отобразить все файлы с веденным типом без учета вложеных каталогов\n");
		printf("03. Поиск слова c учетом вложеных каталогов\n");
		printf("04. Поиск слова без учета вложеных каталогов\n");
		printf("05. Выход\n");
		printf("Пожалуйста, введите число (1-5): "); cin >> ch;

		switch (ch) {
		case '1': displayAllUserFiles(); break;
		case '2': displayNotAllUserFiles(); break;
		case '3': findUserWord(); break;
		case '4': findNotAllUserWord(); break;
		case '5': break;

		default: printf("\a"); break;
		}
	} while (ch != '5');
}

// стартовый интерфейс
void userInterface() {
	setlocale(LC_ALL, "rus");
	char ch;
	do{
		system("cls");
		printf("01. Работа со всеми типами файлов (которые читает ofstream)\n");
		printf("02. Работа с .txt\n");
		printf("03. Работа с .xml\n");
		printf("04. Работа с .html\n");
		printf("05. Работа с выбраным типом файлов\n");
		printf("06. Выход\n");
		printf("Пожалуйста, введите число (1-6): "); cin >> ch;

		switch (ch){
		case '1': userInterfaceAll(); break;
		case '2': userInterfaceTxt(); break;
		case '3': userInterfaceXml(); break;
		case '4': userInterfaceHtml(); break;
		case '5': userInterfaceUserFileType(); break;
		case '6': break;
		default: printf("\a"); break;
		}
	} while (ch != '6');
}

void task() {
	userInterface();
}