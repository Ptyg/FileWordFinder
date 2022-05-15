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
*/
void findObject() {
	FileXml fxml(inputFindingWord(), inputPath());
	fxml.findObject(funcForAll);
	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}

void findNotAllObject(){
	FileXml fxml(inputFindingWord(), inputPath());
 	fxml.findObject(funcForNotAll);
	std::cout << "[INFO]: Press \"Enter\" to continue...";
	std::cin.ignore(); std::cin.get();
}