#include "FileXml.hpp"
#include "FileTxt.hpp"
#include "outResultBase.hpp"
#include "outResultXml.hpp"

#include <iostream>

std::string inputFindingWord(){
	std::string findingWord;
	std::cout << "\nEnter word to find: "; std::cin >> findingWord; 
	return findingWord;
}

std::filesystem::path inputPath() {
	std::string dir;
	std::cout << "\nEnter path to the dir\n(Attention! The path must be written without using Cyrillic characters)\n: ";
	std::cin >> dir;

	std::filesystem::path dirPath = std::filesystem::path(dir);
	return dirPath;
}

//////////////////////////////////////////////////////
//
// FOR .TXT
//  
//////////////////////////////////////////////////////

// Display .txt types of files, 
// taking into account all directories and without
void displayTxtFiles() {
	FileTxt ftxt(inputPath());
	const auto files = ftxt.getDirectoryFiles(true);

	for (const auto& currentFile : files)
		std::cout << currentFile << '\n';

	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

void displayNotAllTxtFiles() {
	FileTxt ftxt(inputPath());
	const auto files = ftxt.getDirectoryFiles();

	for (const auto& currentFile : files)
		std::cout << currentFile << '\n';

	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

// Search for word in .txt, taking into account 
// all directories and without
void findWord() {	
	FileTxt ftxt(inputPath(), inputFindingWord());
	auto results = ftxt.findWord(true);

	for (const auto& i : results) {
		std::cout << "Word: " << i._findWord << '\n';
		std::cout << "Path: " << i._filePath << '\n';
		std::cout << "Line: " << i._line << '\n';
		std::cout << "Line number: " << i._lineNumber << "\n\n";
	}
	
	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

void findNotAllWord() {
	FileTxt ftxt(inputPath(), inputFindingWord());
	auto results = ftxt.findWord();

	for (const auto& i : results) {
		std::cout << "Word: " << i._findWord << '\n';
		std::cout << "Path: " << i._filePath << '\n';
		std::cout << "Line: " << i._line << '\n';
		std::cout << "Line number: " << i._lineNumber << "\n\n";
	}

	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

//////////////////////////////////////////////////////
//
// FOR .XML
//  
//////////////////////////////////////////////////////

// Display .xml files, 
// taking into account all directories and without
void displayXmlFiles() {
	FileXml fxml(inputPath());
	const auto files = fxml.getDirectoryFiles(true);

	for (const auto& currentFile : files)
		std::cout << currentFile << '\n';

	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

void displayNotAllXmlFiles(){
	FileXml fxml(inputPath());
	const auto files = fxml.getDirectoryFiles();

	for (const auto& currentFile : files)
		std::cout << currentFile << '\n';

	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

// Search for objects in xml, taking into account 
// all directories and without
void findObject() {
	FileXml fxml(inputPath(), inputFindingWord());
	auto results = fxml.findObject(true);

	for (const auto& i : results){
		std::cout << "Word: " << i._findWord << '\n';
		std::cout << "File path: " << i._filePath << '\n';

		std::cout << "Object path: ";
		for (const auto& curr_object : i._objects)
			std::cout << curr_object;

		std::cout << "\nObject: " << i._wordObject << '\n';
		std::cout << "Line: " << i._line << '\n';
		std::cout << "Line number: " << i._lineNumber << "\n\n";
	}

	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

void findNotAllObject(){
	FileXml fxml(inputPath(), inputFindingWord());
 	auto results = fxml.findObject();

	for (const auto& i : results){
		std::cout << "Word: " << i._findWord << '\n';
		std::cout << "File path: " << i._filePath << '\n';

		std::cout << "Object path: ";
		for (const auto& curr_object : i._objects)
			std::cout << curr_object;

		std::cout << "\nObject: " << i._wordObject << '\n';
		std::cout << "Line: " << i._line << '\n';
		std::cout << "Line number: " << i._lineNumber << "\n\n";
	}
	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

//////////////////////////////////////////////////////
//
// CUI (console user interface)
//  
//////////////////////////////////////////////////////

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
		std::cout << "Please, enter your choice (1-5): "; 
		std::cin >> ch;

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
		std::cout << "01. Work with .txt\n";
		std::cout << "02. Work with .xml\n";
		std::cout << "03. Exit\n";
		std::cout << "Please, enter your choice (1-3): "; 
		std::cin >> ch;

		switch (ch){
			case '1': userInterfaceTxt(); break;
			case '2': userInterfaceXml(); break;
			case '3': break;
			default: std::cout << "\a"; break;
		}
	} while (ch != '3');
}

int main(){
	userInterface();
	return 0;
}