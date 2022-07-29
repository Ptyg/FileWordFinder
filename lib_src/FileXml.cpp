#include <iostream>
#include <fstream>
#include <memory>
#include <future>
#include <mutex>

#include "FileXml.hpp"
#include "Timer.hpp"

FileXml::FileXml(const std::filesystem::path& path, const std::string& findingWord /* = " " */){
	_extention = ".xml";
	_word = std::move(findingWord);
	_path = path;
}

FileXml::FileXml(std::filesystem::path&& path, std::string&& findingWord /* = " " */){
	_extention = ".xml";
	_word = std::move(findingWord);
	_path = std::move(path);
}

// mutex for findObjectInFileXml()
static std::mutex mutXml;

/*
	Returns result after searching for object in xml

	@ std::vector<OutResultXml>& results - container for results
	@ const std::filesystem::path& currPath - path to file
	@ const std::string& findingWord - word to find

	p.s this function created for async call. F.e you would like to search in several files for object and
		in async way. So this function for this   
*/
static void findObjectInFileXml(std::vector<OutResultXml>& results, const std::filesystem::path& currPath, const std::string& findingWord){
	std::ifstream file{};
	std::string line{};
	std::vector<std::string> objects{};
	std::string tag{};
	constexpr char FIRST_BRACKET = '<', SECOND_BRACKET = '>';
	int counter = 1;

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
				for (size_t j = i - 1; j > 0; j--) {
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

	try{
		file.open(currPath.string());
		while (getline(file, line)) {
			spaceBarEraserFromFront(line);
			
			size_t firstObjectBracketPos = line.find(FIRST_BRACKET);
			size_t secondObjectBracketPos = line.find(SECOND_BRACKET);
			size_t objectWordLengthWithBracket = secondObjectBracketPos - firstObjectBracketPos;
			
			if (objectWordLengthWithBracket < line.size() - 1) {
				if (line.find(findingWord) != std::string::npos) {
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
					mutXml.lock();
					results.push_back(OutResultXml(findingWord, currPath, objects, tag, line, counter));
					mutXml.unlock();
				}
			}
			else { 
				objects.push_back(line); 	
			}

			counter++;
			tag.clear();
			line.clear();
		}
		objects.clear();
		file.close();
	}
	catch(const std::exception& ex){
		std::cout << "[ERROR]: " << ex.what() << "\n";
		file.close();
	}

	if (0 == results.size())
		std::cout << "\n[INFO]: No files with this word\n"; 
}


std::vector<OutResultXml> FileXml::findObject(bool collect_recursivly /* = false */) {
	std::vector<OutResultXml> results;
	const auto files = getDirectoryFiles(collect_recursivly);

	#if DO_TIMER_FILE_XML_FIND_OBJECT
		Timer t("FileXml::findObject");
	#endif // DO_TIMER_FILE_XML_FIND_OBJECT

	#if DO_WITH_ASYNC_XML
		std::vector<std::future<void>> futures;
		for (const auto& currentFile : files)
			futures.push_back(std::async(std::launch::async, findObjectInFileXml, std::ref(results), std::ref(currentFile), std::ref(_word)));
		// to wait for all threads. Like gather() in python
		for (auto& currentFuture : futures)
			currentFuture.get();
	#else
		for (const auto& currentFile : files)
			findObjectInFileXml(results, currentFile, _word);	
	#endif // DO_WITH_ASYNC_XML

	return results;
}