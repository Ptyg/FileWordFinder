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

#ifndef FILESYSTEM
#define FILESYSTEM
#include <filesystem>
namespace fs = std::filesystem;
#endif

#include "task.h"
#include "FileHtml.h"
#include "FileTxt.h"
#include "FileXml.h"
#include "FileAll.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;

/////////////////////////////////////////////////////
//
//	FUNCTIONS TO GET FILES NAME OR PATH FROM DIRS
//
/////////////////////////////////////////////////////
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
	for (auto& p : fs::recursive_directory_iterator(dir)) {
		if (fs::is_regular_file(p)) {
			if (ext.empty() || find(ext.begin(), ext.end(), p.path().extension().string()) != ext.end())
				files.push_back(p.path().filename().string());
		}
	}
	return files;
}

//////////////////////////////////////////////////////
//
// FOR .TXT
//  
//////////////////////////////////////////////////////

// Display .txt types of files, 
// taking into account all directories and without
void displayTxtFiles() {
	FileTxt ftxt; 
	ftxt.displayFiles();
	cin.ignore(); cin.get();
}
void displayNotAllTxtFiles() {
	FileTxt ftxt; 
	ftxt.displayNotAllFiles();
	cin.ignore(); cin.get();
}

// Search for word in .txt, taking into account 
// all directories and without
void findWord() {
	FileTxt ftxt; 
	ftxt.findWordAll();
	cin.ignore(); cin.get();
}
void findNotAllWord() {
	FileTxt ftxt; 
	ftxt.findWordNotAll();
	cin.ignore(); cin.get();
}

//////////////////////////////////////////////////////
//
// FOR .XML
//  
//////////////////////////////////////////////////////

// Display .xml types of files, 
// taking into account all directories and without
void displayXmlFiles() {
	FileXml fxml; 
	fxml.displayFiles();
	cin.ignore(); cin.get();
}
void displayNotAllXmlFiles(){
	FileXml fxml; 
	fxml.displayNotAllFiles();
	cin.ignore(); cin.get();
}

// Search for objects in xml, taking into account 
// all directories and without
void findObject() {
	FileXml fxml; 
	fxml.findObject();
	cin.ignore(); cin.get();
}
void findNotAllObject(){
	FileXml fxml; 
	fxml.findNotAllObject();
	cin.ignore(); cin.get();
}

//////////////////////////////////////////////////////
//
// FOR .HTML
//  
//////////////////////////////////////////////////////

// Display .html types of files, 
// taking into account all directories and without
void displayHtmlFiles() {
	FileHtml fhtml; 
	fhtml.displayFiles();
	cin.ignore(); cin.get();
}
void displayNotAllHtmlFiles() {
	FileHtml fhtml; 
	fhtml.displayNotAllFiles();
	cin.ignore(); cin.get();
}

// TODO: MAKE FINDING FOR SMTH IN HTML

//////////////////////////////////////////////////////
//
// FOR "ALL" FILE TYPE
//  
//////////////////////////////////////////////////////

// display all types of files, 
// taking into account all directories and without
void displayAllFiles() {
	FileAll fall; 
	fall.displayFiles();
	cin.ignore(); cin.get();
}
void displayNotAllFiles() {
	FileAll fall; 
	fall.displayNotAllFiles();
	cin.ignore(); cin.get();
}

// Search for words in all files, taking into account 
// all directories and without
void findWordAll() {
	FileAll fall; 
	fall.findWordAll();
	cin.ignore(); cin.get();
}
void findNotAllWordAll() {
	FileAll fall; 
	fall.findWordNotAll();
	cin.ignore(); cin.get();
}

//////////////////////////////////////////////////////
//
// INTERFAÑES FOR EACH FILE TYPE
//  
//////////////////////////////////////////////////////

void userInterfaceAll() {
	char ch;
	do {
		system("cls");
		printf("01. Show all files including subdirectories\n");
		printf("02. Show all files without subdirectories\n");
		printf("03. Word searching including subdirectories\n");
		printf("04. Word searching without subdirectories\n");
		printf("05. Exit\n");
		printf("Please, enter your choice (1-5): "); cin >> ch;

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
		printf("01. Show all .txt files including subdirectories\n");
		printf("02. Show all .txt files without subdirectories\n");
		printf("03. Word searching including subdirectories\n");
		printf("04. Word searching without subdirectories\n");
		printf("05. Exit\n");
		printf("Please, enter your choice (1-5): "); cin >> ch;

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
		printf("01. Show all .xml files including subdirectories\n");
		printf("02. Show all .xml files without subdirectories\n");
		printf("03. Object(-s) searching including subdirectories\n");
		printf("04. Object(-s) searching without subdirectories\n");
		printf("05. Exit\n");
		printf("Please, enter your choice (1-5): "); cin >> ch;

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
		printf("01. Show all .html files including subdirectories\n");
		printf("02. Show all .html files without subdirectories\n");
		printf("03. Exit\n");
		printf("Please, enter your choice (1-3): "); cin >> ch;

		switch (ch) {
		case '1': displayHtmlFiles(); break;
		case '2': displayNotAllHtmlFiles(); break;
		case '3': break;

		default: printf("\a"); break;
		}
	} while (ch != '3');
}

// Start interface
void userInterface() {
	char ch;
	do{
		system("cls");
		printf("01. Work with chosen file type (in process...)\n");
		printf("02. Work with .txt\n");
		printf("03. Work with .xml\n");
		printf("04. Work with .html (for now, only show files...)\n");
		printf("05. Exit\n");
		printf("Please, enter your choice (1-5): "); cin >> ch;

		switch (ch){
		case '1': /*userInterfaceAll();*/ break;
		case '2': userInterfaceTxt(); break;
		case '3': userInterfaceXml(); break;
		case '4': userInterfaceHtml(); break;
		case '5': break;
		default: printf("\a"); break;
		}
	} while (ch != '5');
}

void task() { userInterface(); }