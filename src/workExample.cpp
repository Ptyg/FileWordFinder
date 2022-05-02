#include "workExample.hpp"
#include "FileTxt.hpp"
#include "FileXml.hpp"
#include "getDirectoryFiles.hpp"
#include "getNotAllDirectoryFiles.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

std::string inputFindingWord(){
	std::string findingWord;
	std::cout << "\nEnter word to find: "; std::cin >> findingWord; 
	return findingWord;
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
	ftxt.setPath();
	std::function<std::vector<std::string>(const fs::path& dir, 
										   const std::vector<std::string>& ext)> func = getDirectoryFiles;
	ftxt.showFilesInDir(func);
	std::cin.ignore(); std::cin.get();
}

void displayNotAllTxtFiles() {
	FileTxt ftxt;
	ftxt.setPath();
	std::function<std::vector<std::string>(const fs::path& dir, 
										   const std::vector<std::string>& ext)> func = getNotAllDirectoryFiles;
	ftxt.showFilesInDir(func);
	std::cin.ignore(); std::cin.get();
}

// Search for word in .txt, taking into account 
// all directories and without
void findWord() {
	FileTxt ftxt(inputFindingWord());
	ftxt.showResultsFromAllDirs();
	std::cin.ignore(); std::cin.get();
}

void findNotAllWord() {
	FileTxt ftxt(inputFindingWord());
	ftxt.showResultsFromNotAllDirs();
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
	
}

void displayNotAllXmlFiles(){

}

// Search for objects in xml, taking into account 
// all directories and without
void findObject() {
	FileXml fxml(inputFindingWord()); 
	fxml.showResultsFromAllDirs();
	std::cin.ignore(); std::cin.get();
}

void findNotAllObject(){
	FileXml fxml(inputFindingWord()); 
	fxml.showResultsFromNotAllDirs();
	std::cin.ignore(); std::cin.get();
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

// Start interface
void userInterface() {
	char ch;
	do{
		std::cout << "01. Work with chosen file type (in process...)\n";
		std::cout << "02. Work with .txt\n";
		std::cout << "03. Work with .xml\n";
		std::cout << "04. Exit\n";
		std::cout << "Please, enter your choice (1-4): "; std::cin >> ch;

		switch (ch){
		case '1': break;
		case '2': userInterfaceTxt(); break;
		case '3': userInterfaceXml(); break;
		case '4': break;
		default: std::cout << "\a"; break;
		}
	} while (ch != '4');
}

void example() { 
	userInterface(); 
}