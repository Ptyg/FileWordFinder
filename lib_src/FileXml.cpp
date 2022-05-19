#include "FileXml.hpp"
#include "getDirectoryFiles.hpp"
#include "getNotAllDirectoryFiles.hpp"

#include <iostream>
#include <fstream>
#include <memory>

FileXml::FileXml() { 
	setFileType(".xml"); 
}

FileXml::FileXml(const std::string& findingWord){
	setFileType(".xml"); 
	setFindWord(findingWord);
}

FileXml::FileXml(std::string&& findingWord){
	setFileType(".xml");
	setFindWord(std::move(findingWord));
}

FileXml::FileXml(const std::filesystem::path& path){
	setFileType(".xml"); 
	setPath(path);
}

FileXml::FileXml(std::filesystem::path&& path){
	setFileType(".xml"); 
	setPath(std::move(path));
}

FileXml::FileXml(const std::string& findingWord, const std::filesystem::path& path){
	setFileType(".xml"); 
	setFindWord(findingWord);
	setPath(path);
}

FileXml::FileXml(const std::string& findingWord, std::filesystem::path&& path){
	setFileType(".xml"); 
	setFindWord(findingWord);
	setPath(std::move(path));
}

FileXml::FileXml(std::string&& findingWord, std::filesystem::path&& path){
	setFileType(".xml"); 
	setFindWord(std::move(findingWord));
	setPath(std::move(path));
}

FileXml::FileXml(std::string&& findingWord, const std::filesystem::path& path){
	setFileType(".xml");
	setFindWord(std::move(findingWord));
	setPath(path);
}

std::vector<OutResultXml> FileXml::findObject(const std::function<std::vector<std::string>(const fs::path& dir, 
											  const std::vector<std::string>& ext)>& func) {
	std::vector<OutResultXml> results;
	int counterFile = 0;

	/*erases spaces before text*/
	auto spaceBarEraserFromFront = [](std::string& line) {
		size_t spaceBarCounter = 0, count = 0;
		while (line[count] == ' ' && count < line.size()) { 
			spaceBarCounter++; 
			count++; 
		}
		line.erase(0, spaceBarCounter);
	};

	/*deleted all extra objects after analysis*/
	auto deleteExtraObjects = [](std::vector<std::string>& obj) {
		constexpr char SLASH = '/';

		// i - obj with slash, j - without slash
		for (size_t i = obj.size() - 1; i > 0; i--) {
			std::string tmp;
			if (obj[i][1] == SLASH) {
				tmp = obj[i];
				tmp.erase(remove(tmp.begin(), tmp.end(), SLASH), tmp.end()); 
				// extra pop beacause it need it
				tmp.pop_back();
				size_t lenToCrop = tmp.size();

				//find the same object and delte both
				for (size_t j = i - 1; j >= 0; j--) {
					std::string tmp2;
					if (obj[j].size() > lenToCrop) {
						tmp2 = obj[j];
						tmp2.erase(tmp2.begin() + lenToCrop, tmp2.end());
						
						if (0 == tmp2.compare(tmp)) { 
							obj.erase(obj.begin() + i); 
							obj.erase(obj.begin() + j); 
						}
						break;
					}
				}
			}
		}
	};

	auto doFinding = [&](const std::vector<std::string>& files, const std::string& findingWord) {
		for (const auto& currentFile : files) {
			std::ifstream file;
			std::string line;
			std::vector<std::string> objects;
			constexpr char FIRST_BRACKET = '<', SECOND_BRACKET = '>';
			int counter = 1;

			try {
				file.open(currentFile);
				while (getline(file, line)) {

					size_t firstObjectBracketPos = line.find(FIRST_BRACKET);
					size_t secondObjectBracketPos = line.find(SECOND_BRACKET);
					size_t objectWordLengthWithBracket = secondObjectBracketPos - firstObjectBracketPos;
					spaceBarEraserFromFront(line);

					if (objectWordLengthWithBracket < line.size() - 1) {
						if (line.find(findingWord) != std::string::npos) {
							std::string tag;

							spaceBarEraserFromFront(line);

							// loop to designate object
							for (size_t i = 0; i < line.size(); i++) {
								if (line[i] == '>') {
									tag.push_back(line[i]);
									break;
								}
								tag.push_back(line[i]);
							}

							deleteExtraObjects(objects);
							results.push_back(OutResultXml(findingWord, currentFile, objects, tag, line, counter));
							counterFile++;
						}
					}
					else { 
						objects.push_back(line); 	
					}
					counter++;
				}
			}
			catch (const std::exception& ex) {
				std::cout << "[ERROR]: " << ex.what() << "\n";
				file.close();
			}
			file.close();
		}

		if (0 == counterFile) { 
			std::cout << "[INFO]: No files with this word"; 
		}
		std::cout << "\n";
	};

	const auto files = collectFiles(func);
	
	std::cout << "[INFO]: Finding word...\n";
	doFinding(files, getFindWord());
	
	return results;
}




