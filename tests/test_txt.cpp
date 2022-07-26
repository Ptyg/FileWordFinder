#include "gtest/gtest.h"
#include "FileTxt.hpp"

// method_whatDoing_whatExpected
/*
TEST(fileTxt, getFileTypeWithBasicConstr_ReturnFileType_TxtFileTypeReturned){    
    FileTxt ftxt;
    
    EXPECT_EQ(ftxt.getFileType(), ".txt");
}

TEST(fileTxt, getFileTypeWithPathMoveConstr_ReturnFileType_TxtFileTypeReturned){    
    std::filesystem::path path{"C:\\Dir"};

    FileTxt ftxt(std::move(path));
    
    EXPECT_EQ(ftxt.getFileType(), ".txt");
}

TEST(fileTxt, getFileTypeWithPathCopyConstr_ReturnFileType_TxtFileTypeReturned){    
    std::filesystem::path path{"C:\\Dir"};

    FileTxt ftxt(path);
    
    EXPECT_EQ(ftxt.getFileType(), ".txt");
}

TEST(fileTxt, getFileTypeWithFindingWordMoveConstr_ReturnFileType_TxtFileTypeReturned){    
    std::string word{"word"};

    FileTxt ftxt(std::move(word));
    
    EXPECT_EQ(ftxt.getFileType(), ".txt");
}

TEST(fileTxt, getFileTypeWithFindingWordCopyConstr_ReturnFileType_TxtFileTypeReturned){    
    std::string word{"word"};

    FileTxt ftxt(word);
    
    EXPECT_EQ(ftxt.getFileType(), ".txt");
}

TEST(fileTxt, getFileTypeWithFullCopyConstr_ReturnFileType_TxtFileTypeReturned){    
    std::filesystem::path path{"C:\\Dir"};
    std::string word{"word"};

    FileTxt ftxt(std::move(word), std::move(path));
    
    EXPECT_EQ(ftxt.getFileType(), ".txt");
}

TEST(fileTxt, getFileTypeWithFullMoveConstr_ReturnFileType_TxtFileTypeReturned){    
    std::filesystem::path path{"C:\\Dir"};
    std::string word{"word"};

    FileTxt ftxt(word, path);
    
    EXPECT_EQ(ftxt.getFileType(), ".txt");
}

TEST(fileTxt, getWordWithBasicConstr_ReturnEmptyWord_EmptyStringReturned){
    FileTxt ftxt;
    
    EXPECT_EQ(ftxt.getFindWord(), "");
}

TEST(fileTxt, getWordWithPathMoveConstr_ReturnEmptyWord_EmptyStringReturned){
    std::filesystem::path path{"C:\\Dir"};

    FileTxt ftxt(std::move(path));
    
    EXPECT_EQ(ftxt.getFindWord(), "");
}

TEST(fileTxt, getWordWithPathCopyConstr_ReturnEmptyWord_EmptyStringReturned){
    std::filesystem::path path{"C:\\Dir"};

    FileTxt ftxt(path);
    
    EXPECT_EQ(ftxt.getFindWord(), "");
}

TEST(fileTxt, getWordWithWordMoveConstr_ReturnSetWord_SetStringReturned){
    std::string word{"word"};

    FileTxt ftxt(std::move(word));
    
    EXPECT_EQ(ftxt.getFindWord(), "word");
}

TEST(fileTxt, getWordWithWordCopyConstr_ReturnSetWord_SetStringReturned){
    std::string word{"word"};

    FileTxt ftxt(word);
    
    EXPECT_EQ(ftxt.getFindWord(), "word");
}

TEST(fileTxt, getWordWithFullMoveConstr_ReturnSetWord_SetWordReturned){
    std::filesystem::path path{"C:\\Dir"};
    std::string word{"word"};

    FileTxt ftxt(std::move(word), std::move(path));
    
    EXPECT_EQ(ftxt.getFindWord(), "word");
}

TEST(fileTxt, getWordWithFullCopyConstr_ReturnSetWord_SetWordReturned){
    std::filesystem::path path{"C:\\Dir"};
    std::string word{"word"};

    FileTxt ftxt(word, path);
    
    EXPECT_EQ(ftxt.getFindWord(), "word");
}
*/