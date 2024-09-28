//this file is used to connect the file holding the main function and the files together.
#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <filesystem>
using namespace std;

//The classes used in this program are declared in this file. The classed are define in separate files.
//this is the main class used in this program.
class TextEditor {
public:
    TextEditor(); //constructor for this class
    void startEditor(); //method for the TextEditor class
    void openNewFile(); //method for the TextEditor class
    void displayFiles(); //method for the TextEditor class
    void openTextFile(); //method for the TextEditor class

    vector<string> textFiles; //list of text files saved by the program. Class Attribute
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
   // void saveFile(const string &fileName); This function turns out to not be needed. The fstream method autosave with out being told. 
    void fileMenu(const string &fileName);
    
    //TextFile attributes
    string fileName;
};

#endif