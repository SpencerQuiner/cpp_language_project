#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <filesystem>
using namespace std;

//main class for the entire program.
class TextEditor {
public:
    TextEditor();
    void startEditor();
    void openNewFile();
    void displayFiles();
    void openTextFile();

    vector<string> textFiles; //list of text files saved by the program.
    private:
    void loadTextFiles(const string &directoryPath);
};

//class for individual text file.
class TextFile {
public:
    //constructor declared for this class type.
    TextFile(const string &fileName); 

    //TextFile methods
    void editFile(const string &fileName);
    void deleteFile(const string &fileName);
    void saveFile(const string &fileName);
    
    //TextFile attributes
    string fileName;
    time_t createdDate;
    time_t lastEdit;
};

#endif