#include <iostream>
#include <memory>
#include <fstream>
#include <mutex>
#include <future>

#include "FileTxt.hpp"
#include "Timer.hpp"

FileTxt::FileTxt(const std::filesystem::path& path, const std::string& findingWord /* = " " */){
	_extention = ".txt";
	_path = path;
	_word = findingWord;
}

FileTxt::FileTxt(std::filesystem::path&& path, std::string&& findingWord /* = " " */){
	_extention = ".txt"; 
	_path = std::move(path);
	_word = std::move(findingWord);
}

// mutex for findObjectInFileTxt()
static std::mutex mutTxt;

/*
	Returns result after searching for word in txt

	@ std::vector<OutResult>& results - container for results
	@ const std::filesystem::path& currPath - path to file
	@ const std::string& findingWord - word to find

	p.s this function created for async call. F.e you would like to search in several files for word and
		in async way. So this function for this   
*/
static void findObjectInFileTxt(std::vector<OutResult>& results, const std::filesystem::path& currPath, const std::string& findingWord){
	std::ifstream file;
	std::string line;
	int lineCounter = 1;

	try {
		file.open(currPath.string());
		while (getline(file, line)) {
			if (line.find(findingWord) != std::string::npos) {
				int spaceBarCounter = 0, coun = 0;
				while (line[coun] == ' ') { spaceBarCounter++; coun++; }
				line.erase(0, spaceBarCounter);
				results.push_back(OutResult(findingWord, currPath, line, lineCounter));
			}
			lineCounter++;
		}
	}
	catch (const std::exception& ex) {
		std::cout << "[ERROR]: " << ex.what() << "\n";
		file.close();
	}
	file.close();

	if (0 == results.size())
		std::cout << "\n[INFO]: No files with this word\n";
}

std::vector<OutResult> FileTxt::findWord(bool collect_recursivly /* = false */){
	int counterFile = 0;
	std::vector<OutResult> results;
	
	const auto files = getDirectoryFiles(collect_recursivly);
	
	std::cout << "[INFO]: Finding word...\n";

	#if DO_TIMER_FILE_TXT_FIND_WORD
		Timer t("FileTxt::findObject");
	#endif // DO_TIMER_FILE_TXT_FIND_WORD

	#if DO_WITH_ASYNC_TXT
		std::vector<std::future<void>> futures;
		for (const auto& currentFile : files)
			futures.push_back(std::async(std::launch::async, findObjectInFileTxt, std::ref(results), std::ref(currentFile), std::ref(_word)));

		// to wait for all threads. Like gather() in python
		for (auto& currentFuture : futures)
			currentFuture.get();

	#else
		for (const auto& currentFile : files)
			findObjectInFileTxt(results, currentFile, _word);	
	#endif // DO_WITH_ASYNC_TXT

	return results;
}