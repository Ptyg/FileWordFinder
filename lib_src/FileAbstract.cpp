#include <iostream>
#include <memory>

#include "FileAbstract.hpp"
#include "Timer.hpp"


std::vector<std::filesystem::path> FileAbstract::getDirectoryFiles(bool collect_recursivly /*= false*/) 
{
	std::vector<std::filesystem::path> outFiles;
	
#if DO_TIMER_FILE_ABSTRACT_GET_DIR_FILES
    Timer t("FileAbstract::getDirectoryFiles");
#endif
    auto collectFiles = [&](const auto& dir_iterator){
        for (const auto& p : dir_iterator) {    
            if (std::filesystem::is_regular_file(p) && _extention == p.path().extension().string())
                    outFiles.push_back(p.path());
        }
        return 0; // need to return something, zero is fine
    };
    
    (collect_recursivly) ? collectFiles(std::filesystem::recursive_directory_iterator(_path)) 
                         : collectFiles(std::filesystem::directory_iterator(_path));
    return outFiles;
}