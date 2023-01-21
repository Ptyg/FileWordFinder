#ifndef OUT_RESULT_XML
#define OUT_RESULT_XML

#include "outResultBase.hpp"

#include <vector>
#include <string>

/*
Data structure for result that we get from finding word in xmls
*/
class OutResultXml : public OutResult {
public:
    std::vector<std::string> m_objects;
    std::string m_wordObject;

    OutResultXml(std::string&& findWord, std::string&& file, 
                 std::vector<std::string>&& objects, std::string&& wordObject, 
                 std::string&& line, int lineNumber) 
        : OutResult(std::move(findWord), std::move(file), std::move(line), lineNumber), 
        m_objects(std::move(objects)), m_wordObject(std::move(wordObject)) {}
};

#endif