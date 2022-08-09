#include "gtest/gtest.h"
#include "FileTxt.hpp"

// method_whatDoing_whatExpected

enum typeOfColecting{
    flagToCollectRecursivly = true,
    flagToCollectNotRecursivly = false
};

/*--------------------------------- Collect file path from dir -------------------------------------*/
TEST(FileTxt, collectFilesFromDirectoryRecursivly){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\test_files");

    auto files = ftxt.getDirectoryFiles(flagToCollectRecursivly);

    EXPECT_TRUE(files.size() == 4);
}

TEST(FileTxt, collectFilesFromDirectoryNotRecursivly){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\test_files");

    auto files = ftxt.getDirectoryFiles(flagToCollectNotRecursivly);

    EXPECT_TRUE(files.size() == 2);
}
/*--------------------------------------------------------------------------------------------------*/

/*------------------------- Throwing exception because of nonexistent dir --------------------------*/
TEST(FileTxt, throwsExceptionBecauseOfNotExestentDir){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\notExistentDir");

    EXPECT_THROW(ftxt.getDirectoryFiles( /*flag is not necessary */ ), std::filesystem::filesystem_error);
}
/*--------------------------------------------------------------------------------------------------*/

/*----------------------------------- Find word in files -------------------------------------------*/
TEST(FileTxt, findWordInTxtsInDirectoryRecursivly){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\test_files", "cat");
    
    auto results = ftxt.findWord(flagToCollectRecursivly);

    EXPECT_TRUE(results.size() > 0);
}

TEST(FileTxt, findWordInTxtsInDirectoryNotRecursivly){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\test_files", "cat");
    
    auto results = ftxt.findWord(flagToCollectNotRecursivly);

    EXPECT_TRUE(results.size() > 0);
}
/*--------------------------------------------------------------------------------------------------*/

/*-------------------------------- Cannot find word in files ---------------------------------------*/
TEST(FileTxt, noResultBecauseOfNoWordInFile_Recursivly) {
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\test_files", "VeeeeryLooooongStriiiiingThatdoesn`tExist");
    
    auto results = ftxt.findWord(flagToCollectRecursivly);

    EXPECT_TRUE(results.size() == 0);
}

TEST(FileTxt, noResultBecauseOfNoWordInFile_notRecursivly){
    FileTxt ftxt(std::filesystem::current_path().string() + "..\\..\\test_files", "VeeeeryLooooongStriiiiingThatdoesn`tExist");
    
    auto results = ftxt.findWord(flagToCollectNotRecursivly);

    EXPECT_TRUE(results.size() == 0);
}
/*--------------------------------------------------------------------------------------------------*/
