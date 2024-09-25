#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

//main class for the entire program.
class TextEditor {
public:
    void startEditor();
    void openNewFile();
    void displayFiles();
    void openTextFile();

    vector<string> textFiles; //list of text files saved by the program.
};

//class for individual text file.
class TextFile {
public:
    void editFile();
    void deleteFile();
    void saveFile();

    string fileName;
    time_t createdDate;
    time_t lastEdit;
};

#endif