#include "gtest/gtest.h"
#include "FileXml.hpp"

std::string path = {c}

TEST(fileXml, getFileTypeWithBasicConstr_ReturnFileType_XmlFileTypeReturned){    
    FileXml fxml;
    
    EXPECT_EQ(fxml.getFileType(), ".xml");
}

TEST(fileXml, getFileTypeWithPathMoveConstr_ReturnFileType_XmlFileTypeReturned){    
    std::filesystem::path path{"C:\\Dir"};

    FileXml fxml(std::move(path));
    
    EXPECT_EQ(fxml.getFileType(), ".xml");
}

TEST(fileXml, getFileTypeWithPathCopyConstr_ReturnFileType_XmlFileTypeReturned){    
    std::filesystem::path path{"C:\\Dir"};

    FileXml fxml(path);
    
    EXPECT_EQ(fxml.getFileType(), ".xml");
}

TEST(fileXml, getFileTypeWithFindingWordMoveConstr_ReturnFileType_XmlFileTypeReturned){    
    std::string word{"word"};

    FileXml ftxt(std::move(word));
    
    EXPECT_EQ(ftxt.getFileType(), ".xml");
}

TEST(fileXml, getFileTypeWithFindingWordCopyConstr_ReturnFileType_XmlFileTypeReturned){    
    std::string word{"word"};

    FileXml ftxt(word);
    
    EXPECT_EQ(ftxt.getFileType(), ".xml");
}

TEST(fileXml, getFileTypeWithFullCopyConstr_ReturnFileType_XmlFileTypeReturned){    
    std::filesystem::path path{"C:\\Dir"};
    std::string word{"word"};

    FileXml ftxt(std::move(word), std::move(path));
    
    EXPECT_EQ(ftxt.getFileType(), ".xml");
}

TEST(fileXml, getFileTypeWithFullMoveConstr_ReturnFileType_XmlFileTypeReturned){    
    std::filesystem::path path{"C:\\Dir"};
    std::string word{"word"};

    FileXml ftxt(word, path);
    
    EXPECT_EQ(ftxt.getFileType(), ".xml");
}

TEST(fileXml, getWordWithBasicConstr_ReturnEmptyWord_EmptyStringReturned){
    FileXml fxml;
    
    EXPECT_EQ(fxml.getFindWord(), "");
}

TEST(fileXml, getWordWithPathMoveConstr_ReturnEmptyWord_EmptyStringReturned){
    std::filesystem::path path{"C:\\Dir"};
    
    FileXml fxml(std::move(path));
    
    EXPECT_EQ(fxml.getFindWord(), "");
}

TEST(fileXml, getWordWithPathCopyConstr_ReturnEmptyWord_EmptyStringReturned){
    std::filesystem::path path{"C:\\Dir"};
    
    FileXml fxml(path);
    
    EXPECT_EQ(fxml.getFindWord(), "");
}

TEST(fileTxt, getWordWithWordMoveConstr_ReturnSetWord_SetStringReturned){
    std::string word{"word"};

    FileXml fxml(std::move(word));
    
    EXPECT_EQ(fxml.getFindWord(), "word");
}

TEST(fileTxt, getWordWithWordCopyConstr_ReturnSetWord_SetStringReturned){
    std::string word{"word"};

    FileXml fxml(word);
    
    EXPECT_EQ(fxml.getFindWord(), "word");
}

TEST(fileTxt, getWordWithFullMoveConstr_ReturnSetWord_SetWordReturned){
    std::filesystem::path path{"C:\\Dir"};
    std::string word{"word"};

    FileXml fxml(std::move(word), std::move(path));
    
    EXPECT_EQ(fxml.getFindWord(), "word");
}

TEST(fileTxt, getWordWithFullCopyConstr_ReturnSetWord_SetWordReturned){
    std::filesystem::path path{"C:\\Dir"};
    std::string word{"word"};

    FileXml fxml(word, path);
    
    EXPECT_EQ(fxml.getFindWord(), "word");
}
