#ifndef OUT_RESULT_XML
#define OUT_RESULT_XML

#include "outResultBase.hpp"

#include <vector>
#include <string>

/*
Data structure for result that we get from finding word in xmls
*/
class OutResultXml : public OutResult {
    std::vector<std::string> _objects;
    std::string _wordObject;
public:
    OutResultXml() = default;
    OutResultXml(std::string&& findWord, std::filesystem::path&& file, std::vector<std::string>&& objects, 
                 std::string&& wordObject, std::string&& line, int&& lineNumber) 
        : OutResult(std::move(findWord), std::move(file), std::move(line), std::move(lineNumber)), 
        _objects(std::move(objects)), _wordObject(std::move(wordObject)){}

    OutResultXml(const std::string& findWord, const std::filesystem::path& file, const std::vector<std::string>& objects, 
                 const std::string& wordObject, const std::string& line, const int& lineNumber) 
        : OutResult(findWord, file, line, lineNumber),
        _objects(objects), _wordObject(wordObject){}

    std::vector<std::string> getObjects() const;
    std::string getWordObject() const;
};

#endif