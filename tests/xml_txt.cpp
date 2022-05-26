#include "gtest/gtest.h"
#include "FileXml.hpp"
#include "FileTxt.hpp"
#include "getDirectoryFiles.hpp"
#include "getNotAllDirectoryFiles.hpp"

TEST(fileTxtXml, FileType){
    FileTxt ftxt;
    FileXml fxml;
    
    EXPECT_EQ(ftxt.getFileType(), ".txt");
    EXPECT_EQ(fxml.getFileType(), ".xml");

}

TEST(fileTxtXml, DefaultConstructor){
    FileTxt ftxt;
    FileXml fxml;
    
    EXPECT_EQ(ftxt.getDirPath(), "");
    EXPECT_EQ(ftxt.getFindWord(), "");
    EXPECT_EQ(fxml.getDirPath(), "");
    EXPECT_EQ(fxml.getFindWord(), ""); 
}

TEST(fileTxtXml, MovePathConstruct){
    std::filesystem::path path1{"C:\\Dir"};
    std::filesystem::path path2{"C:\\Dir"};
    
    FileTxt ftxt(std::move(path1));    
    FileXml fxml(std::move(path2));

    EXPECT_EQ(ftxt.getDirPath(), "C:\\Dir");
    EXPECT_EQ(ftxt.getFindWord(), "");
    EXPECT_EQ(fxml.getDirPath(), "C:\\Dir");
    EXPECT_EQ(fxml.getFindWord(), "");
}

TEST(fileTxtXml, PathConstruct){
    std::filesystem::path path{"C:\\Dir"};
    
    FileTxt ftxt(path);
    FileTxt fxml(path);
    
    EXPECT_EQ(ftxt.getDirPath(), "C:\\Dir");
    EXPECT_EQ(ftxt.getFindWord(), "");
    EXPECT_EQ(fxml.getDirPath(), "C:\\Dir");
    EXPECT_EQ(fxml.getFindWord(), "");
}

TEST(fileTxtXml, MoveFindingWordConstruct){
    std::string word1{"word"};
    std::string word2{"word"};

    FileTxt ftxt(std::move(word1));
    FileTxt fxml(std::move(word2));

    EXPECT_EQ(ftxt.getFindWord(), "word");
    EXPECT_EQ(ftxt.getDirPath(), "");
    EXPECT_EQ(fxml.getFindWord(), "word");
    EXPECT_EQ(fxml.getDirPath(), "");
}

TEST(fileTxtXml, FindingWordConstruct){
    std::string word{"word"};
    
    FileTxt ftxt(word);
    FileTxt fxml(word);

    EXPECT_EQ(ftxt.getFindWord(), "word");
    EXPECT_EQ(ftxt.getDirPath(), "");
    EXPECT_EQ(fxml.getFindWord(), "word");
    EXPECT_EQ(fxml.getDirPath(), "");
}

TEST(fileTxtXml, moveFullConstruct){
    std::string word1{"word"};
    std::filesystem::path path1{"C:\\Dir"};
    std::string word2{"word"};
    std::filesystem::path path2{"C:\\Dir"};

    FileTxt ftxt(std::move(word1), std::move(path1));
    FileXml fxml(std::move(word2), std::move(path2));

    EXPECT_EQ(ftxt.getDirPath(), "C:\\Dir");
    EXPECT_EQ(ftxt.getFindWord(), "word");
    EXPECT_EQ(fxml.getDirPath(), "C:\\Dir");
    EXPECT_EQ(fxml.getFindWord(), "word");    
}

TEST(fileTxtXml, CopyFullConstruct){
    std::string word{"word"};
    std::filesystem::path path{"C:\\Dir"};

    FileTxt ftxt(word, path);
    FileXml fxml(word, path);

    EXPECT_EQ(ftxt.getDirPath(), "C:\\Dir");
    EXPECT_EQ(ftxt.getFindWord(), "word");
    EXPECT_EQ(fxml.getDirPath(), "C:\\Dir");
    EXPECT_EQ(fxml.getFindWord(), "word");   
}

TEST(fileTxt, collectTxtFilesWithSubDirs){
    std::filesystem::path path{"C:\\NotExcitedDir"};
    
    EXPECT_NO_THROW(getDirectoryFiles(path, {".webm"}));
}