#include "getNotAllDirectoryFiles.hpp"
#include "Log.hpp"

std::vector<std::filesystem::path> getNotAllDirectoryFiles(const std::filesystem::path& dir, 
													  	   const std::vector<std::string_view>& ext) {
	std::vector<std::filesystem::path> files;
	try{
		for (const auto& p : std::filesystem::directory_iterator(dir)) {
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