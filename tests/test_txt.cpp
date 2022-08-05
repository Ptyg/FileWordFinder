#include "gtest/gtest.h"
#include "FileTxt.hpp"

// method_whatDoing_whatExpected

enum typeOfColecting{
    flagToCollectRecursivly = true,
    flagToCollectNotRecursivly = false
};

/*--------------------------------- Collect file path from dir -------------------------------------*/
TEST(getDirectoryFiles, collectFilesFromDirectoryRecursivly, vectorOfPaths){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\test_files");

    auto files = ftxt.getDirectoryFiles(flagToCollectRecursivly);

    EXPECT_TRUE(files.size() == 4);
}

TEST(getDirectoryFiles, collectFilesFromDirectoryNotRecursivly, vectorOfPaths){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\test_files");

    auto files = ftxt.getDirectoryFiles(flagToCollectNotRecursivly);

    EXPECT_TRUE(files.size() == 2);
}
/*--------------------------------------------------------------------------------------------------*/

/*------------------------- Throwing exception because of nonexistent dir --------------------------*/
TEST(getDirectoryFiles, collectFilesFromNonexistentDirectoryRecursivly, exception){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\notExistentDir");

    EXPECT_THROW(ftxt.getDirectoryFiles(flagToCollectRecursivly), std::filesystem::filesystem_error);
}

TEST(getDirectoryFiles, collectFilesFromNonexistentDirectoryNotRecursivly, vectorOfPaths){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\notExistentDir");

    EXPECT_THROW(ftxt.getDirectoryFiles(flagToCollectNotRecursivly), std::filesystem::filesystem_error);
}
/*--------------------------------------------------------------------------------------------------*/

/*----------------------------------- Find word in files -------------------------------------------*/
TEST(findWord, findWordInTxtsInDirectoryRecursivly, vectorOfResults){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\test_files", "cat");
    
    auto results = ftxt.findWord(flagToCollectRecursivly);

    EXPECT_TRUE(results.size() > 0);
}

TEST(findWord, findWordInTxtsInDirectoryNotRecursivly, vectorOfResults){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\test_files", "cat");
    
    auto results = ftxt.findWord(flagToCollectNotRecursivly);

    EXPECT_TRUE(results.size() > 0);
}
/*--------------------------------------------------------------------------------------------------*/

/*-------------------------------- Cannot find word in files ---------------------------------------*/
TEST(findWord, findWordInTxtsInDirectoryRecursivly, vectorOfResults){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\test_files", "VeeeeryLooooongStriiiiingThatdoesn`tExist");
    
    auto results = ftxt.findWord(flagToCollectRecursivly);

    EXPECT_TRUE(results.size() == 0);
}

TEST(findWord, findWordInTxtsInDirectoryNotRecursivly, vectorOfResults){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\test_files", "VeeeeryLooooongStriiiiingThatdoesn`tExist");
    
    auto results = ftxt.findWord(flagToCollectNotRecursivly);

    EXPECT_TRUE(results.size() == 0);
}
/*--------------------------------------------------------------------------------------------------*/
