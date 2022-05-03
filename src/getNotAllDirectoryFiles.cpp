#include "getNotAllDirectoryFiles.hpp"

#include <iostream>

std::vector<std::string> getNotAllDirectoryFiles(const fs::path& dir, const std::vector<std::string>& ext) {
	std::vector<std::string> files;
	try{
		for (const auto& p : fs::directory_iterator(dir)) {
			if (fs::is_regular_file(p)) {
				if (ext.empty() || find(ext.begin(), ext.end(), p.path().extension().string()) != ext.end())
					files.push_back(p.path().string());
			}
		}
	}
	catch (const std::exception& ex){
		std::cout << "[ERROR]: " << ex.what() << "\n";
	}
	return files;
}