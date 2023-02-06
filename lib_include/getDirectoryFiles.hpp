#include "Log.hpp"

#include <vector>
#include <string_view>
#include <filesystem>

template<typename iterator = std::filesystem::directory_iterator,
         typename path = std::string_view, 
         typename iteratable_vect = std::vector<std::string_view>>
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
		log::console_log(ex.what(), "[ERROR]");
	}
	return files;
}

