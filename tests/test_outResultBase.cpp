#include "gtest/gtest.h"
#include "outResultBase.hpp"

#include <filesystem>

// method_whatDoing_whatExpected

TEST(outResult, getFindWordWithMoveConstr_getFindWord_wordReturned){
    OutResult foo("word", "filePath", "line", 4);

    EXPECT_EQ(foo.getFindWord(), "word");
}

TEST(outResult, getFindWordWithCopyConstr_getFindWord_wordReturned){
    std::string word{"word"};
    std::filesystem::path path{"filePath"};
    std::string line{"line"};
    int lineNum{10};
    
    OutResult foo(word, path, line, lineNum);

    EXPECT_EQ(foo.getFindWord(), "word");
}

TEST(outResult, getFilePathWithMoveConstr_getFilePath_filePathReturned){
    OutResult foo("word", "filePath", "line", 4);

    EXPECT_EQ(foo.getfilePath(), "filePath");
}

TEST(outResult, getFilePathWithCopyConstr_getFilePath_filePathReturned){
    std::string word{"word"};
    std::filesystem::path path{"filePath"};
    std::string line{"line"};
    int lineNum{10};
    
    OutResult foo(word, path, line, lineNum);

    EXPECT_EQ(foo.getfilePath(), "filePath");
}

TEST(outResult, getLineWithMoveConstr_getLine_lineReturned){
    OutResult foo("word", "filePath", "line", 4);

    EXPECT_EQ(foo.getLine(), "line");
}

TEST(outResult, getLineWithCopyConstr_getLine_lineReturned){
    std::string word{"word"};
    std::filesystem::path path{"filePath"};
    std::string line{"line"};
    int lineNum{10};

    OutResult foo(word, path, line, lineNum);
    
    EXPECT_EQ(foo.getLine(), "line");
}

TEST(outResult, getLineNumberWithMoveConstr_getLineNumber_LineNumberReturned){
    OutResult foo("word", "path", "line", 4);

    EXPECT_EQ(foo.getLineNumber(), 4);
}

TEST(outResult, getLineWithCopyConstr_getLineNumber_LineNumberReturned){
    std::string word{"word"};
    std::filesystem::path path{"filePath"};
    std::string line{"line"};
    int lineNum{10};

    OutResult foo(word, path, line, lineNum);
    
    EXPECT_EQ(foo.getLineNumber(), 10);
}