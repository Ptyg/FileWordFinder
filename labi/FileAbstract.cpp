#include "task.h"

void FileAbstract::SaveFile::saveInfo(string word, string path, int& lineNum, string& line, FileAbstract::SaveFile obj) {
	ofstream fout;
	try{
		fout.open(obj._fileName, ofstream::app);
		fout << "Word: " << word << "\n";
		fout << "Path: " << path << "\n";
		fout << "Line number: " << lineNum << "\n";
		fout << "Line: " << line << "\n\n";
		cout << "Данные сохранены!\n";
		fout.close();
	}
	catch (const std::exception& ex) { cout << ex.what() << "\n"; fout.close(); }
}
void FileAbstract::SaveFile::saveInfo2(vector<string> word, string path, int& lineNum, string& line, FileAbstract::SaveFile obj) {
	ofstream fout;
	try {
		fout.open(obj._fileName, ofstream::app);
		fout << "Words: ";
		for (int i = 0; i < word.size(); i++) { fout << word[i] << ' '; } cout << "\n\n";
		fout << "Path: " << path << "\n";
		fout << "Line number: " << lineNum << "\n";
		fout << "Line: " << line << "\n\n";
		cout << "Данные сохранены!\n";
		fout.close();
	}
	catch (const std::exception& ex) { cout << ex.what() << "\n"; fout.close(); }
}
void FileAbstract::SaveFile::saveInfo3(string tag, string path, int& lineNum, string& line, FileAbstract::SaveFile obj) {
	ofstream fout;
	try {
		fout.open(obj._fileName, ofstream::app);
		fout << "Tag: " << tag; 
		for (int i = 0; i < tag.size(); i++) { if (tag[i] == '<') { tag.insert(i + 1, string("/")); break; }}
		fout << tag << "\n";
		fout << "Path: " << path << "\n";
		fout << "Line number: " << lineNum << "\n";
		fout << "Line: " << line << "\n\n";
		cout << "Данные сохранены!\n";
		fout.close();
	}
	catch (const std::exception& ex) { cout << ex.what() << "\n"; fout.close(); }
}
