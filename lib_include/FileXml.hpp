#ifndef FILE_XML_H
#define FILE_XML_H

#include "FileAbstract.hpp"
#include "outResultXml.hpp"
#include "Log.hpp"

#include <fstream>

class FileXml : public FileAbstract {
public:
	FileXml(std::string_view findingWord, std::string_view path);

	template<typename iterator = std::filesystem::directory_iterator>
	std::vector<OutResultXml> findObject() {
		const auto files = getDirectoryFiles<iterator>(m_dirPath, m_fileTypes);

		log::console_log("Finding object...", "[INFO]");

		int counterFile = 0;
		std::vector<OutResultXml> results;

		//erases spaces before text
		auto spaceBarEraserFromFront = [](std::string& line) {
			size_t spaceBarCounter = 0, count = 0;
			while (line[count] == ' ' && count < line.size()) { 
				spaceBarCounter++; 
				count++; 
			}
			line.erase(0, spaceBarCounter);
		};

		//deleted all extra objects after analysis
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

		std::ifstream file;
		std::string line, tag;
		std::vector<std::string> objects;
		constexpr char FIRST_BRACKET = '<', SECOND_BRACKET = '>';
		int counter = 1;

		for (const auto& currentFile : files) {
			try {
				file.open(currentFile.string());
				while (getline(file, line)) {
					spaceBarEraserFromFront(line);
					
					auto firstObjectBracketPos = line.find(FIRST_BRACKET);
					auto secondObjectBracketPos = line.find(SECOND_BRACKET);
					auto objectWordLengthWithBracket = secondObjectBracketPos - firstObjectBracketPos;
					
					if (objectWordLengthWithBracket < line.size() - 1) {
						if (line.find(m_word) != std::string::npos) {
							tag.clear();
							// loop to designate object
							for (size_t i = 0; i < line.size(); i++) {
								if (line[i] == '>') {
									tag.push_back(line[i]);
									break;
								}
								tag.push_back(line[i]);
							}

							deleteExtraObjects(objects);							
							results.push_back(OutResultXml(m_word.data(), currentFile.string(), 
														std::move(objects), std::move(tag), 
														std::move(line), counter));
							counterFile++;
						}
					}
					else { 
						objects.push_back(line); 	
					}
					counter++;
					tag.clear();
					line.clear();
				}
			}
			catch (const std::exception& ex) {
				log::console_log(ex.what(), "[ERROR]");
				file.close();
			}
			file.close();
		}

		if (0 == counterFile) { 
			log::console_log("No files with this word", "[INFO]");
		}

		return results;
	}
};

#endif
