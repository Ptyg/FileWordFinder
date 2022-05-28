#include "outResultXml.hpp"

std::vector<std::string> OutResultXml::getObjects() const{
    return _objects;
}

std::string OutResultXml::getWordObject() const{
    return _wordObject;
}