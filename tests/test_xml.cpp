#include "gtest/gtest.h"
#include "FileXml.hpp"

TEST(fileXml, getFileTypeWithBasicConstr_ReturnFileType_XmlFileTypeReturned){    
    FileXml fxml;
    
    EXPECT_EQ(fxml.getFileType(), ".xml");
}

TEST(fileTxt, getFileTypeWithPathMoveConstr_ReturnFileType_XmlFileTypeReturned){    
    std::filesystem::path path{"C:\\Dir"};

    FileXml fxml(std::move(path));
    
    EXPECT_EQ(fxml.getFileType(), ".xml");
}

TEST(fileTxt, getFileTypeWithPathCopyConstr_ReturnFileType_XmlFileTypeReturned){    
    std::filesystem::path path{"C:\\Dir"};

    FileXml fxml(path);
    
    EXPECT_EQ(fxml.getFileType(), ".xml");
}

TEST(fileTxt, getFileTypeWithFindingWordMoveConstr_ReturnFileType_XmlFileTypeReturned){    
    std::string word{"word"};

    FileXml ftxt(std::move(word));
    
    EXPECT_EQ(ftxt.getFileType(), ".xml");
}

TEST(fileTxt, getFileTypeWithFindingWordCopyConstr_ReturnFileType_XmlFileTypeReturned){    
    std::string word{"word"};

    FileXml ftxt(word);
    
    EXPECT_EQ(ftxt.getFileType(), ".xml");
}

TEST(fileTxt, getFileTypeWithFullCopyConstr_ReturnFileType_XmlFileTypeReturned){    
    std::filesystem::path path{"C:\\Dir"};
    std::string word{"word"};

    FileXml ftxt(std::move(word), std::move(path));
    
    EXPECT_EQ(ftxt.getFileType(), ".xml");
}

TEST(fileTxt, getFileTypeWithFullMoveConstr_ReturnFileType_XmlFileTypeReturned){    
    std::filesystem::path path{"C:\\Dir"};
    std::string word{"word"};

    FileXml ftxt(word, path);
    
    EXPECT_EQ(ftxt.getFileType(), ".xml");
}
