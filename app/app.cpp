#include "FileXml.hpp"
#include "FileTxt.hpp"
#include "outResultBase.hpp"
#include "outResultXml.hpp"
#include "getDirectoryFiles.hpp"

#include <iostream>
#include <cstdio>

void clear_scr() {
	std::cout << "\x1b[2J"; 
	std::cout << "\x1b[H";
}

[[nodiscard]] std::string inputFindingWord(){
	std::string findingWord;
	std::cout << "\nEnter word to find: ";
	std::cin >> findingWord;
	return findingWord;
}

[[nodiscard]] std::string inputPath() {
	std::string dir;
	std::cout << "\nEnter path to the dir\n(Attention! The path must be written without using Cyrillic characters)\n: ";
	std::cin >> dir;	
	return dir;
}

template<typename paths = std::vector<std::filesystem::path>>
void show_paths(paths&& cont) {
	uint16_t iter = 0;
	for (const auto& currentFile : cont)
		std::cout << ++iter << ": " << currentFile << '\n';
}

template<typename results = std::vector<OutResult>>
void show_results(results&& cont) {
	uint16_t iter = 0;
	for (const auto& i : cont) {
		std::cout << ">>>> " << ++iter << " <<<<\n";
		std::cout << "Word: " << i.m_findWord << '\n';
		std::cout << "Path: " << i.m_filePath << '\n';
		std::cout << "Line: " << i.m_line << '\n';
		std::cout << "Line number: " << i.m_lineNumber << '\n';

		if constexpr (std::is_same<results, std::vector<OutResultXml>>::value) {
			std::cout << "Word object: " << i.m_wordObject << '\n';		
			std::cout << "Object path: ";
			for (const auto& j : i.m_objects) {
				std::cout << j;
			}
			std::cout << '\n';
		}
	}
}

template<typename iterator = std::filesystem::directory_iterator,
		 typename container = std::vector<std::string_view>> 
void displayFileTypes(std::string_view path, container&& file_types) {
	const auto files = getDirectoryFiles<iterator>(path, std::forward<container>(file_types));

	std::cout << "Results\n\n";
	show_paths(files);

	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

//////////////////////////////////////////////////////
//
// FOR .TXT
//  
//////////////////////////////////////////////////////

template<typename iterator = std::filesystem::directory_iterator>
void findWord() {
	FileTxt ftxt(inputFindingWord(), inputPath());
	auto results = ftxt.findWord<iterator>();

	std::cout << "Results\n\n";
	show_results(results);
	
	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

//////////////////////////////////////////////////////
//
// FOR .XML
//  
//////////////////////////////////////////////////////

template<typename iterator = std::filesystem::directory_iterator>
void findObject() {
	FileXml fxml(inputFindingWord(), inputPath());
	const auto results = fxml.findObject<iterator>();

	std::cout << "Results\n\n";
	show_results(results);
	
	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

//////////////////////////////////////////////////////
//
// CUI (console user interface)
//  
//////////////////////////////////////////////////////

void userInterfaceTxt() {
	char ch{};
	do {
		clear_scr();
		std::cout << "01. Show all .txt files including subdirectories\n";
		std::cout << "02. Show all .txt files without subdirectories\n";
		std::cout << "03. Word searching including subdirectories\n";
		std::cout << "04. Word searching without subdirectories\n";
		std::cout << "05. Exit\n";
		std::cout << "Please, enter your choice (1-5): ";
		std::cin >> ch;
		
		switch (ch) {
		case '1': {
			displayFileTypes<std::filesystem::recursive_directory_iterator>(inputPath(), { ".txt" }); 
			break;
		}
		case '2': {
			displayFileTypes(inputPath(), { ".txt" }); 
			break;
		}
		case '3': findWord<std::filesystem::recursive_directory_iterator>(); break;
		case '4': findWord(); break;
		case '5': break;
		default: break;
		}
	} while (ch != '5');
}

void userInterfaceXml() {
	char ch{};
	do {
		clear_scr();
		std::cout << "01. Show all .xml files including subdirectories\n";
		std::cout << "02. Show all .xml files without subdirectories\n";
		std::cout << "03. Object(-s) searching including subdirectories\n";
		std::cout << "04. Object(-s) searching without subdirectories\n";
		std::cout << "05. Exit\n";
		std::cout << "Please, enter your choice (1-5): "; 
		std::cin >> ch;

		switch (ch) {
		case '1': {
			displayFileTypes<std::filesystem::recursive_directory_iterator>(inputPath(), { ".xml" }); 
			break;
		}
		case '2': {
			displayFileTypes(inputPath(), { ".txt" }); 
			break;
		}		
		case '3': findObject<std::filesystem::recursive_directory_iterator>(); break;
		case '4': findObject(); break;
		case '5': break;
		default: break;
		}
	} while (ch != '5');
}

// Start interface
void userInterface() {
	char ch;
	do{
		clear_scr();
		std::cout << "01. Work with .txt\n";
		std::cout << "02. Work with .xml\n";
		std::cout << "03. Exit\n";
		std::cout << "Please, enter your choice (1-3): "; 
		std::cin >> ch;

		switch (ch){
		case '1': userInterfaceTxt(); break;
		case '2': userInterfaceXml(); break;
		case '3': break;
		default: break;
		}
	} while (ch != '3');
}

int main(){
	/*
		This needs to activate ansi in windows cmd & powershell. 
		Without it - doesn`t work properly.
	*/
	#if _WIN32
		system("");
	#endif

	userInterface();
	return 0;
}