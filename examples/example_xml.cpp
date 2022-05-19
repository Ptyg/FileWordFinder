/*
getDirectoryFiles / getNotAllDirectoryFiles: just collect files including subdirectories or
											 without 

implementation of these functions you can find in lib_src dir
*/
std::function<std::vector<std::string>(const fs::path& dir, 
									   const std::vector<std::string>& ext)> funcForAll = getDirectoryFiles;

std::function<std::vector<std::string>(const fs::path& dir, 
									   const std::vector<std::string>& ext)> funcForNotAll = getNotAllDirectoryFiles;

/*
collectFiles: Takes a func that collecting files with specific extention. (In this case - txt)
				Extention type already exists in each class.  
			    So, you can use your collecting function. All what you need to do
				is create the std::function object. Example of collecting function you can check in 
			    lib_src dir. In result - vector contains results to each file with metadata

Result looks like this <<with subdirs>>:
	Enter path: C:\\SuperProject\\DirWithXmls 
		C:\\SuperProject\\DirWithXmls\\test_subdir\\test_sub_xml1.xml
		C:\\SuperProject\\DirWithXmls\\test_subdir\\test_sub_xml2.xml
		C:\\SuperProject\\DirWithXmls\\test_xml1.xml
		C:\\SuperProject\\DirWithXmls\\test_xml2.xml
*/

void displayXmlFiles() {
	FileXml fxml(inputPath());
	const auto files = fxml.collectFiles(funcForAll);

	for (const auto& currentFile : files)
		std::cout << currentFile << '\n';

	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

void displayNotAllXmlFiles(){
	FileXml fxml(inputPath());
	const auto files = fxml.collectFiles(funcForNotAll);

	for (const auto& currentFile : files)
		std::cout << currentFile << '\n';

	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

/*
findObject: in this func we`ll see all xml files including files 
		    in subdirs containing word "password" and some metadata

Result looks like this:
	Enter path: C:\\SuperProject\\DirWithXmls
	Enter word: EXE
		
		Word: EXE
		File path: C:\Programming\FileHelper\FileWordFinder\test_files\test_xml1.xml
		Object path: <?xml version="1.0"?><Tests xmlns="http://www.adatum.com"><Test TestId="0001" TestType="CMD">
		Object: <CommandLine>
		Line: <CommandLine>Examp1.EXE</CommandLine>
		Line number: 5

		Word: EXE
		File path: C:\Programming\FileHelper\FileWordFinder\test_files\test_xml1.xml
		Object path: <?xml version="1.0"?><Tests xmlns="http://www.adatum.com"><Test TestId="0002" TestType="CMD">
		Object: <CommandLine>
		Line: <CommandLine>Examp2.EXE</CommandLine>
		Line number: 11

	<<without subdirs looks similarly>>:
*/

void findObject() {
	FileXml fxml(inputFindingWord(), inputPath());
	auto results = fxml.findObject(funcForAll);

	for (const auto& i : results){
		auto objectPath = i.getObjects();

		std::cout << "Word: " << i.getFindWord() << '\n';
		std::cout << "File path: " << i.getfilePath() << '\n';

		std::cout << "Object path: ";
		for (const auto& object : objectPath)
			std::cout << object;

		std::cout << "\nObject: " << i.getWordObject() << '\n';
		std::cout << "Line: " << i.getLine() << '\n';
		std::cout << "Line number: " << i.getLineNumber() << '\n';
	}

	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

void findNotAllObject(){
	FileXml fxml(inputFindingWord(), inputPath());
 	auto results = fxml.findObject(funcForAll);

	for (const auto& i : results){
		auto objectPath = i.getObjects();

		std::cout << "Word: " << i.getFindWord() << '\n';
		std::cout << "File path: " << i.getfilePath() << '\n';

		std::cout << "Object path: ";
		for (const auto& object : objectPath)
			std::cout << object;

		std::cout << "\nObject: " << i.getWordObject() << '\n';
		std::cout << "Line: " << i.getLine() << '\n';
		std::cout << "Line number: " << i.getLineNumber() << '\n';
	}
	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}