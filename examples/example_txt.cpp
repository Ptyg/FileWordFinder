/*
getDirectoryFiles / getNotAllDirectoryFiles: just collect files including subdirectories or
											 without 

implementation of these functions you can find in lib_src dir
*/
std::function<std::vector<std::string>(const fs::path& dir, 
									   const std::vector<std::string>& ext)> funcForAll = getDirectoryFiles;

std::function<std::vector<std::string>(const fs::path& dir, 
									   const std::vector<std::string>& ext)> funcForNotAll = getNotAllDirectoryFiles;


/*------------------------------ TXT ------------------------------*/

/*
collectFiles: Takes a func that collecting files with specific extention. (In this case - txt)
				Extention type already exists in each class.  
			    So, you can use your collecting function. All what you need to do
				is create the std::function object. Example of collecting function you can check in 
			    lib_src dir. In result - vector contains results to each file with metadata

displayTxtFiles: in this func we`ll see all txt files in the directory and subdirectories recursively

displayNotAllTxtFiles: in this func we`ll see all txt files in the directory but without subdirectories

Result looks like this <<with subdirs>>:
	Enter path: C:\\SuperProject\\DirWithTxts 
		C:\\SuperProject\\DirWithTxts\\test_subdir\\test_sub_txt1.txt
		C:\\SuperProject\\DirWithTxts\\test_subdir\\test_sub_txt2.txt
		C:\\SuperProject\\DirWithTxts\\test_txt1.txt
		C:\\SuperProject\\DirWithTxts\\test_txt2.txt

<<Or without subdirs>>
	Enter path: C:\\SuperProject\\DirWithTxts
		C:\\SuperProject\\DirWithTxts\\test_txt1.txt
		C:\\SuperProject\\DirWithTxts\\test_txt2.txt
*/
void displayTxtFiles() {
	FileTxt ftxt("C:\\SuperProject\\DirWithTxts");
	const auto files = ftxt.collectFiles(funcForAll);

	for (const auto& currentFile : files)
		std::cout << currentFile << '\n';

	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

void displayNotAllTxtFiles() {
	FileTxt ftxt("C:\\SuperProject\\DirWithTxts");
	const auto files = ftxt.collectFiles(funcForNotAll);

	for (const auto& currentFile : files)
		std::cout << currentFile << '\n';

	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

/*
findWord: in this func we`ll see all txt files including files 
		  in subdirs containing word "password" and some metadata

Result looks like this <<with subdirs>>:
	Enter path: C:\\SuperProject\\DirWithTxts
	Enter word: Cat
		Searching word: Cat
		Path to file: C:\\SuperProject\\DirWithTxts\\test_txt1.txt
		Line number: 11
		Line: Cat communication includes vocalizations like meowing, purring, trilling, hissing,

		Searching word: Cat
		Path to file: C:\\SuperProject\\DirWithTxts\\test_subdir\\test_sub_txt1.txt
		Line number: 17
		Line: Cats also secrete and perceive pheromones.

	<<without subdirs looks similarly>>:
*/
void findWord() {	
	FileTxt ftxt("password", "C:\\SuperProject\\Passwords");
	auto results = ftxt.findWord(funcForAll);

	for (const auto& i : results) {
		std::cout << "Word: " << i.getFindWord() << '\n';
		std::cout << "Path: " << i.getfilePath() << '\n';
		std::cout << "Line: " << i.getLine() << '\n';
		std::cout << "Line number: " << i.getLineNumber() << "\n\n";
	}
	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

void findNotAllWord() {
	FileTxt ftxt("name", "C:\\SuperProject\\Passwords");
	auto results = ftxt.findWord(funcForNotAll);

	for (const auto& i : results) {
		std::cout << "Word: " << i.getFindWord() << '\n';
		std::cout << "Path: " << i.getfilePath() << '\n';
		std::cout << "Line: " << i.getLine() << '\n';
		std::cout << "Line number: " << i.getLineNumber() << "\n\n";
	}
	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}


