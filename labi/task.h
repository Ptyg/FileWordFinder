#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <chrono>
#include "FileTxt.h"
#include "FileAll.h"
#include "FileAbstract.h"
#include "FileXml.h"
#include "FileHtml.h"
#include "FileUserType.h"

namespace fs = std::filesystem;

using std::cin;
using std::cout;
using std::string;
using std::stringstream;
using std::vector;
using std::ifstream;
using std::ofstream;


vector<string> getDirectoryFiles(const fs::path& dir, const vector<string>& ext);
vector<string> getNotAllDirectoryFiles(const fs::path& dir, const vector<string>& ext);
vector<string> getDirectoryFilesNames(const fs::path& dir, const vector<string>& ext);
vector<string> getDirectoryNotAllFilesNames(const fs::path& dir, const vector<string>& ext);

void task();
void userInterface();