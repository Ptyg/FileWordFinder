#include "task.hpp"
#include "FileHtml.hpp"
#include "FileTxt.hpp"
#include "FileXml.hpp"
#include "FileAll.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;

/////////////////////////////////////////////////////
//
//	FUNCTIONS TO GET FILES NAME OR PATH FROM DIRS
//
/////////////////////////////////////////////////////
std::vector<std::string> getDirectoryFiles(const fs::path& dir, const std::vector<std::string>& ext) {
	std::vector<std::string> files;
	try{
		for (auto& p : fs::recursive_directory_iterator(dir)) {
			if (fs::is_regular_file(p)) {
				if (ext.empty() || find(ext.begin(), ext.end(), p.path().extension().string()) != ext.end())
					files.push_back(p.path().string());
			}
		}
	}
	catch (const std::exception& ex){
		std::cout << ex.what() << "\n";
		std::cin.ignore(); std::cin.get();
	}
	
	return files;
}

std::vector<std::string> getNotAllDirectoryFiles(const fs::path& dir, const std::vector<std::string>& ext) {
	std::vector<std::string> files;
	try{
		for (auto& p : fs::directory_iterator(dir)) {
			if (fs::is_regular_file(p)) {
				if (ext.empty() || find(ext.begin(), ext.end(), p.path().extension().string()) != ext.end())
					files.push_back(p.path().string());
			}
		}
	}
	catch (const std::exception& ex){
		std::cout << ex.what() << "\n";
		std::cin.ignore(); std::cin.get();
	}
	
	return files;
}

std::vector<std::string> getDirectoryFilesNames(const fs::path& dir, const std::vector<std::string>& ext) {
	std::vector<std::string> files;
	for (auto& p : fs::directory_iterator(dir)) {
		if (fs::is_regular_file(p)) {
			if (ext.empty() || find(ext.begin(), ext.end(), p.path().extension().string()) != ext.end())
				files.push_back(p.path().filename().string());
		}
	}
	return files;
}

std::vector<std::string> getDirectoryNotAllFilesNames(const fs::path& dir, const std::vector<std::string>& ext) {
	std::vector<std::string> files;
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
	std::cin.ignore(); std::cin.get();
}
void displayNotAllTxtFiles() {
	FileTxt ftxt; 
	ftxt.displayNotAllFiles();
	std::cin.ignore(); std::cin.get();
}

// Search for word in .txt, taking into account 
// all directories and without
void findWord() {
	FileTxt ftxt; 
	ftxt.findWordAll();
	std::cin.ignore(); std::cin.get();
}
void findNotAllWord() {
	FileTxt ftxt; 
	ftxt.findWordNotAll();
	std::cin.ignore(); std::cin.get();
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
	std::cin.ignore(); std::cin.get();
}
void displayNotAllXmlFiles(){
	FileXml fxml; 
	fxml.displayNotAllFiles();
	std::cin.ignore(); std::cin.get();
}

// Search for objects in xml, taking into account 
// all directories and without
void findObject() {
	FileXml fxml; 
	fxml.findObject();
	std::cin.ignore(); std::cin.get();
}
void findNotAllObject(){
	FileXml fxml; 
	fxml.findNotAllObject();
	std::cin.ignore(); std::cin.get();
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
	std::cin.ignore(); std::cin.get();
}
void displayNotAllHtmlFiles() {
	FileHtml fhtml; 
	fhtml.displayNotAllFiles();
	std::cin.ignore(); std::cin.get();
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
	std::cin.ignore(); std::cin.get();
}
void displayNotAllFiles() {
	FileAll fall; 
	fall.displayNotAllFiles();
	std::cin.ignore(); std::cin.get();
}

// Search for words in all files, taking into account 
// all directories and without
void findWordAll() {
	FileAll fall; 
	fall.findWordAll();
	std::cin.ignore(); std::cin.get();
}
void findNotAllWordAll() {
	FileAll fall; 
	fall.findWordNotAll();
	std::cin.ignore(); std::cin.get();
}

//////////////////////////////////////////////////////
//
// INTERFAFES FOR EACH FILE TYPE
//  
//////////////////////////////////////////////////////

void userInterfaceAll() {
	char ch;
	do {
		std::cout << "01. Show all files including subdirectories\n";
		std::cout << "02. Show all files without subdirectories\n";
		std::cout << "03. Word searching including subdirectories\n";
		std::cout << "04. Word searching without subdirectories\n";
		std::cout << "05. Exit\n";
		std::cout << "Please, enter your choice (1-5): "; std::cin >> ch;

		switch (ch) {
		case '1': displayAllFiles(); break;
		case '2': displayNotAllFiles(); break;
		case '3': findWordAll(); break;
		case '4': findNotAllWordAll(); break;
		case '5': break;

		default: std::cout << "\a"; break;
		}
	} while (ch != '5');
}

void userInterfaceTxt() {
	char ch;
	do {
		std::cout << "01. Show all .txt files including subdirectories\n";
		std::cout << "02. Show all .txt files without subdirectories\n";
		std::cout << "03. Word searching including subdirectories\n";
		std::cout << "04. Word searching without subdirectories\n";
		std::cout << "05. Exit\n";
		std::cout << "Please, enter your choice (1-5): "; std::cin >> ch;

		switch (ch) {
		case '1': displayTxtFiles(); break;
		case '2': displayNotAllTxtFiles(); break;
		case '3': findWord(); break;
		case '4': findNotAllWord(); break;
		case '5': break;
		default: std::cout << "\a"; break;
		}
	} while (ch != '5');
}

void userInterfaceXml() {
	char ch;
	do {
		std::cout << "01. Show all .xml files including subdirectories\n";
		std::cout << "02. Show all .xml files without subdirectories\n";
		std::cout << "03. Object(-s) searching including subdirectories\n";
		std::cout << "04. Object(-s) searching without subdirectories\n";
		std::cout << "05. Exit\n";
		std::cout << "Please, enter your choice (1-5): "; std::cin >> ch;

		switch (ch) {
		case '1': displayXmlFiles(); break;
		case '2': displayNotAllXmlFiles(); break;
		case '3': findObject(); break;
		case '4': findNotAllObject(); break;
		case '5': break;
		default: std::cout << "\a"; break;
		}
	} while (ch != '5');
}

void userInterfaceHtml() {
	char ch;
	do {
		std::cout << "01. Show all .html files including subdirectories\n";
		std::cout << "02. Show all .html files without subdirectories\n";
		std::cout << "03. Exit\n";
		std::cout << "Please, enter your choice (1-3): "; std::cin >> ch;

		switch (ch) {
		case '1': displayHtmlFiles(); break;
		case '2': displayNotAllHtmlFiles(); break;
		case '3': break;

		default: std::cout << "\a"; break;
		}
	} while (ch != '3');
}

// Start interface
void userInterface() {
	char ch;
	do{
		std::cout << "01. Work with chosen file type (in process...)\n";
		std::cout << "02. Work with .txt\n";
		std::cout << "03. Work with .xml\n";
		std::cout << "04. Work with .html (for now, only show files...)\n";
		std::cout << "05. Exit\n";
		std::cout << "Please, enter your choice (1-5): "; std::cin >> ch;

		switch (ch){
		case '1': /*userInterfaceAll();*/ break;
		case '2': userInterfaceTxt(); break;
		case '3': userInterfaceXml(); break;
		case '4': userInterfaceHtml(); break;
		case '5': break;
		default: std::cout << "\a"; break;
		}
	} while (ch != '5');
}

void task() { 
	userInterface(); 
}