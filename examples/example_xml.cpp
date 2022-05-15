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
ftxt.showFilesInDir: Takes a func that collecting files with specific extention.
                     Extention type already exists in each class
				     So, you can use your collecting function. All what you need to do
				     is create the std::function object. Example of this function you can check in 
				     lib_src dir

displayXmlFiles: in this func we`ll see all xml files in the directory and subdirectories 
				 and sub-subdirectories and... you get it

displayNotAllXmlFiles: in this func we`ll see all xml files in the directory but without subdirectories

Result looks like this:
	Enter path: C:\\SuperProject\\DirWithXmls
		C:\\SuperProject\\DirWithXmls\\test_subdir\\test_sub_xml1.xml
		C:\\SuperProject\\DirWithXmls\\test_subdir\test_sub_xml2.xml
		C:\\SuperProject\\DirWithXmls\\test_xml1.xml
		C:\\SuperProject\\DirWithXmls\\test_xml2.xml

*/
void displayXmlFiles() {
	FileXml fxml("C:\\SuperProject\\DirWithXmls");
	fxml.showFilesInDir(funcForAll);
	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

void displayNotAllXmlFiles(){
	FileXml fxml("C:\\SuperProject\\DirWithXmls");
	fxml.showFilesInDir(funcForNotAll);
	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

/*
findWord: in this func we`ll see all xml files including files 
		  in subdirs containing word "password" and some metadata

findNotAllWord: in this func we`ll see all xml files without 
				files in subdirs containing word "password" and some metadata

Result looks like this:
	Enter path: C:\\SuperProject\\DirWithXmls
	Enter word: EXE
		Object path: <?xml version="1.0"?> <Tests xmlns="http://www.adatum.com"> <Test TestId="0001" TestType="CMD">
		Word`s tag: <CommandLine></CommandLine>
		File`s path: C:\Programming\FileHelper\FileWordFinder\test_files\test_xml1.xml
		Line number: 5
		Line: <CommandLine>Examp1.EXE</CommandLine>


		Object path: <?xml version="1.0"?> <Tests xmlns="http://www.adatum.com"> <Test TestId="0002" TestType="CMD">
		Word`s tag: <CommandLine></CommandLine>
		File`s path: C:\Programming\FileHelper\FileWordFinder\test_files\test_xml1.xml
		Line number: 11
		Line: <CommandLine>Examp2.EXE</CommandLine>

		Object path: <?xml version="1.0"?> <Tests xmlns="http://www.adatum.com"> <Test TestId="0003" TestType="GUI">
		Word`s tag: <CommandLine></CommandLine>
		File`s path: C:\Programming\FileHelper\FileWordFinder\test_files\test_xml1.xml
		Line number: 17
		Line: <CommandLine>Examp2.EXE /Verbose</CommandLine>
*/
void findObject() {
	FileXml fxml("Book", "C:\\SuperProject\\DirWithXmls");
	fxml.findObject(funcForAll);
	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

void findNotAllObject(){
	FileXml fxml("Book", "C:\\SuperProject\\DirWithXmls");
 	fxml.findObject(funcForNotAll);
	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}