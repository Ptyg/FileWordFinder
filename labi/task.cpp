#include "task.h"
#include "FileHtml.h"
#include "FileTxt.h"
#include "FileXml.h"
#include "FileAll.h"

using std::cin;
using std::cout;
using std::string;
using std::stringstream;
using std::vector;
using std::ifstream;
using std::ofstream;

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
// ��� ������ .TXT
//  
//////////////////////////////////////////////////////

// ����������� ���� txt � ������ ���� ���������� � ���
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

// ����� ���� � txt � ������ ���� ���������� � ���
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
// ��� ������ .XML
//  
//////////////////////////////////////////////////////

// ����������� ���� xml � ������ ���� ���������� � ���
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

// ����� �������� � xml � ������ ���� ���������� � ���
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
// ��� ������ .HTML
//  
//////////////////////////////////////////////////////

// ����������� ���� html � ������ ���� ���������� � ���
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

// TODO: ������� ����� ����-�� � ����

//////////////////////////////////////////////////////
//
// ��� ���� ����� ������
//  
//////////////////////////////////////////////////////

// ����������� ���� ����� ������ � ������ ���� ���������� � ���
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

// ����� ���� �� ���� ������ � ������ ���� ���������� � ���
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
// ���������� ��� ������� ���� �����
//  
//////////////////////////////////////////////////////

void userInterfaceAll() {
	char ch;
	do {
		system("cls");
		printf("01. ���������� ��� ����� � �������� � ������ �������� ���������\n");
		printf("02. ���������� ��� ����� � �������� ��� ����� �������� ���������\n");
		printf("03. ����� ����� �� ���� ������ c ������ �������� ���������\n");
		printf("04. ����� ����� �� ���� ������ ��� ����� �������� ���������\n");
		printf("05. �����\n");
		printf("����������, ������� ����� (1-5): "); cin >> ch;

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
		printf("01. ���������� ��� ����� .txt � ������ �������� ���������\n");
		printf("02. ���������� ��� ����� .txt ��� ����� �������� ���������\n");
		printf("03. ����� ����� c ������ �������� ���������\n");
		printf("04. ����� ����� ��� ����� �������� ���������\n");
		printf("05. �����\n");
		printf("����������, ������� ����� (1-5): "); cin >> ch;

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
		printf("01. ���������� ��� ����� .xml � ������ �������� ���������\n");
		printf("02. ���������� ��� ����� .xml ��� ����� �������� ���������\n");
		printf("03. ����� ������� c ������ �������� ���������\n");
		printf("04. ����� ������� ��� ����� �������� ���������\n");
		printf("05. �����\n");
		printf("����������, ������� ����� (1-5): "); cin >> ch;

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
		printf("01. ���������� ��� ����� .html � ������ �������� ���������\n");
		printf("02. ���������� ��� ����� .html ��� ����� �������� ���������\n");
		printf("03. �����\n");
		printf("����������, ������� ����� (1-3): "); cin >> ch;

		switch (ch) {
		case '1': displayHtmlFiles(); break;
		case '2': displayNotAllHtmlFiles(); break;
		case '3': break;

		default: printf("\a"); break;
		}
	} while (ch != '3');
}

// ��������� ���������
void userInterface() {
	setlocale(LC_ALL, "rus");
	char ch;
	do{
		system("cls");
		printf("01. ������ �� ����� ������ ������\n");
		printf("02. ������ � .txt\n");
		printf("03. ������ � .xml\n");
		printf("04. ������ � .html\n");
		printf("05. �����\n");
		printf("����������, ������� ����� (1-5): "); cin >> ch;

		switch (ch){
		case '1': userInterfaceAll(); break;
		case '2': userInterfaceTxt(); break;
		case '3': userInterfaceXml(); break;
		case '4': userInterfaceHtml(); break;
		case '5': break;
		default: printf("\a"); break;
		}
	} while (ch != '5');
}

void task() {
	userInterface();
}