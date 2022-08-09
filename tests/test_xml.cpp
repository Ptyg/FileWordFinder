#include "gtest/gtest.h"
#include "FileXml.hpp"

// method_whatDoing_whatExpected

enum typeOfColecting{
    flagToCollectRecursivly = true,
    flagToCollectNotRecursivly = false
};

/*--------------------------------- Collect file path from dir -------------------------------------*/
TEST(getDirectoryFiles, collectFilesFromDirectoryRecursivly, vectorOfPaths){
    FileXml fxml(std::filesystem::current_path().string() + "..\\..\\test_files");

    auto files = fxml.getDirectoryFiles(flagToCollectRecursivly);

    EXPECT_TRUE(files.size() == 4);
}

TEST(getDirectoryFiles, collectFilesFromDirectoryNotRecursivly, vectorOfPaths){
    FileXml fxml(std::filesystem::current_path().string() + "..\\..\\test_files");

    auto files = fxml.getDirectoryFiles(flagToCollectNotRecursivly);

    EXPECT_TRUE(files.size() == 2);
}
/*--------------------------------------------------------------------------------------------------*/

/*------------------------- Throwing exception because of nonexistent dir --------------------------*/
TEST(getDirectoryFiles, collectFilesFromNonexistentDirectoryRecursivly, exception){
    FileXml fxml(std::filesystem::current_path().string() + "..\\..\\notExistentDir");

    EXPECT_THROW(fxml.getDirectoryFiles(flagToCollectRecursivly), std::filesystem::filesystem_error);
}

TEST(getDirectoryFiles, collectFilesFromNonexistentDirectoryNotRecursivly, vectorOfPaths){
    FileXml fxml(std::filesystem::current_path().string() + "..\\..\\notExistentDir");

    EXPECT_THROW(fxml.getDirectoryFiles(flagToCollectNotRecursivly), std::filesystem::filesystem_error);
}
/*--------------------------------------------------------------------------------------------------*/

/*----------------------------------- Find word in files -------------------------------------------*/
TEST(findWord, findWordInTxtsInDirectoryRecursivly, vectorOfResults){
    FileXml fxml(std::filesystem::current_path().string() + "..\\..\\test_files", "cat");
    
    auto results = fxml.findObject(flagToCollectRecursivly);

    EXPECT_TRUE(results.size() > 0);
}

TEST(findWord, findWordInTxtsInDirectoryNotRecursivly, vectorOfResults){
    FileXml fxml(std::filesystem::current_path().string() + "..\\..\\test_files", "cat");
    
    auto results = fxml.findObject(flagToCollectNotRecursivly);

    EXPECT_TRUE(results.size() > 0);
}
/*--------------------------------------------------------------------------------------------------*/

/*-------------------------------- Cannot find word in files ---------------------------------------*/
TEST(findWord, findWordInTxtsInDirectoryRecursivly, vectorOfResults){
    FileXml fxml(std::filesystem::current_path().string() + "..\\..\\test_files", "VeeeeryLooooongStriiiiingThatdoesn`tExist");
    
    auto results = fxml.findObject(flagToCollectRecursivly);

    EXPECT_TRUE(results.size() == 0);
}

TEST(findWord, findWordInTxtsInDirectoryNotRecursivly, vectorOfResults){
    FileXml fxml(std::filesystem::current_path().string() + "..\\..\\test_files", "VeeeeryLooooongStriiiiingThatdoesn`tExist");
    
    auto results = fxml.findObject(flagToCollectNotRecursivly);

    EXPECT_TRUE(results.size() == 0);
}
/*--------------------------------------------------------------------------------------------------*/
