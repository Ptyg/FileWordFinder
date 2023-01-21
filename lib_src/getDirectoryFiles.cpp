#include "getDirectoryFiles.hpp"
#include "Log.hpp"

/*
	Iterator:
		- std::filesystem::recursive_directory_iterator
		- std::filesystem::directory_iterator
	path: 
		- std::string
		- std::string_view
	iteratetable_vect:
		- std::vector<string or string_view> 
*/
template<typename iterator, typename path, typename iteratable_vect>
std::vector<std::filesystem::path> getDirectoryFiles(path&& dir, iteratable_vect&& ext) {
	std::vector<std::filesystem::path> files;
		
	try{
		for (const auto& p : iterator(dir)) {
			if (std::filesystem::is_regular_file(p)) {
				if (ext.empty() || find(ext.begin(), ext.end(), p.path().extension().string()) != ext.end())
					files.push_back(p.path());
			}
		}
	}
	catch (const std::exception& ex){
		Log::console_log(ex.what(), "[ERROR]");
	}
	return files;
}