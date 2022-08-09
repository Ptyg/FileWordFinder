#include "gtest/gtest.h"
#include "FileXml.hpp"

// method_whatDoing_whatExpected

enum typeOfColecting{
    flagToCollectRecursivly = true,
    flagToCollectNotRecursivly = false
};

/*--------------------------------- Collect file path from dir -------------------------------------*/
TEST(FileXml, collectFilesFromDirectoryRecursivly){
    FileXml fxml(std::filesystem::current_path().string() + "\\..\\..\\test_files");

    auto files = fxml.getDirectoryFiles(flagToCollectRecursivly);

    EXPECT_TRUE(files.size() == 4);
}

TEST(FileXml, collectFilesFromDirectoryNotRecursivly){
    FileXml fxml(std::filesystem::current_path().string() + "\\..\\..\\test_files");

    auto files = fxml.getDirectoryFiles(flagToCollectNotRecursivly);

    EXPECT_TRUE(files.size() == 2);
}
/*--------------------------------------------------------------------------------------------------*/

/*------------------------- Throwing exception because of nonexistent dir --------------------------*/
TEST(FileXml, throwsExceptionBecauseOfNotExestentDir){
    FileXml fxml(std::filesystem::current_path().string() + "\\..\\..\\notExistentDir");

    EXPECT_THROW(fxml.getDirectoryFiles(/* flag is not necessary */), std::filesystem::filesystem_error);
}
/*--------------------------------------------------------------------------------------------------*/

/*----------------------------------- Find word in files -------------------------------------------*/
TEST(FileXml, findObjectInXmls_Recursivly){
    FileXml fxml(std::filesystem::current_path().string() + "\\..\\..\\test_files", "cat");
    
    auto results = fxml.findObject(flagToCollectRecursivly);

    EXPECT_TRUE(results.size() > 0);
}

TEST(FileXml, findObjectInXmls_notRecursivly){
    FileXml fxml(std::filesystem::current_path().string() + "\\..\\..\\test_files", "cat");
    
    auto results = fxml.findObject(flagToCollectNotRecursivly);

    EXPECT_TRUE(results.size() > 0);
}
/*--------------------------------------------------------------------------------------------------*/

/*-------------------------------- Cannot find word in files ---------------------------------------*/
TEST(FileXml, noResultBecauseOfNoWordInFile_Recursivly){
    FileXml fxml(std::filesystem::current_path().string() + "\\..\\..\\test_files", "VeeeeryLooooongStriiiiingThatdoesn`tExist");
    
    auto results = fxml.findObject(flagToCollectRecursivly);

    EXPECT_TRUE(results.size() == 0);
}

TEST(findWord, noResultBecauseOfNoWordInFile_notRecursivly){
    FileXml fxml(std::filesystem::current_path().string() + "\\..\\..\\test_files", "VeeeeryLooooongStriiiiingThatdoesn`tExist");
    
    auto results = fxml.findObject(flagToCollectNotRecursivly);

    EXPECT_TRUE(results.size() == 0);
}
/*--------------------------------------------------------------------------------------------------*/
