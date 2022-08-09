#include <iostream>
#include <memory>
#include <fstream>
#include <mutex>
#include <future>
#include <cctype> // for toupper(), isupper()

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
static void findWordInFileTxt(std::vector<OutResult>& results, const std::filesystem::path& currPath, const std::string& findingWord){
	std::ifstream file{};
	std::string line{};
	int lineCounter = 1;
	bool isWordInLine = false;

	#if NEW_SEARCH_ALGORITHM
	/* 
		Creating regex expr automatically 
		For example:
			finding word: cat
			regex expr will be like this: [Cc][Aa][Tt] 
	*/
	std::string ergExpStr{};
	ergExpStr.reserve(findingWord.size() * 2);

	for (auto& curLetter : findingWord){
		ergExpStr.push_back('[');
		
		if (isupper(curLetter)){
			ergExpStr.push_back(curLetter);
			ergExpStr.push_back(tolower(curLetter));
		}
		else{
			ergExpStr.push_back(curLetter);
			ergExpStr.push_back(toupper(curLetter));
		}

		ergExpStr.push_back(']');
	}

	std::regex regExpr{ergExpStr};
	#endif // NEW_SEARCH_ALGORITHM

	try {
		file.open(currPath.string());
		while (getline(file, line)) {
			#if NEW_SEARCH_ALGORITHMыц
				isWordInLine = std::regex_search(line, regExpr);

			#else // old search
				isWordInLine = line.find(findingWord) != std::string::npos;
			
			#endif // NEW_SEARCH_ALGORITHM
			if (isWordInLine) {
				int spaceBarCounter = 0;

				while (line[spaceBarCounter] == ' ') { spaceBarCounter++; }
				line.erase(0, spaceBarCounter);
				
				#if DO_WITH_ASYNC_TXT
					std::lock_guard<std::mutex> guard(mutTxt);
				#endif
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
}

std::vector<OutResult> FileTxt::findWord(bool collect_recursivly /* = false */){
	std::vector<OutResult> results{};
	std::vector<std::filesystem::path> files{};

	try{
		files = getDirectoryFiles(collect_recursivly);
	}
	catch(std::filesystem::filesystem_error const& err){
		std::cout << "[EXCEPTION]" << err.what() << '\n' 
		<< "Empty container returned" << '\n';
		return results;
	}
	
	#if DO_TIMER_FILE_TXT_FIND_WORD
		Timer t("FileTxt::findWord");
	#endif // DO_TIMER_FILE_TXT_FIND_WORD

	#if DO_WITH_ASYNC_TXT
		std::vector<std::future<void>> futures;
		for (const auto& currentFile : files)
			futures.push_back(std::async(std::launch::async, findWordInFileTxt, std::ref(results), std::ref(currentFile), std::ref(_word)));

		// to wait for all threads. Like gather() in python
		for (auto& currentFuture : futures)
			currentFuture.get();
	#else
		for (const auto& currentFile : files)
			findWordInFileTxt(results, currentFile, _word);	
	
	#endif // DO_WITH_ASYNC_TXT

	if (0 == results.size())
		std::cout << "\n[INFO]: No files with this word\n";
	
	return results;
}