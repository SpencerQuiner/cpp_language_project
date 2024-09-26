#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <filesystem>
#include "TextEditor.h"
using namespace std;
namespace std_filesystem = std::filesystem;

TextEditor::TextEditor(){
    //populates the TextEditor vector
    string directoryPath = "./TextEditorFiles";
    loadTextFiles(directoryPath);
}

void TextEditor::startEditor() {
    int selection = 0;
    //main menu for the program.
    do{
    cout << "Type the number of an option from the menu to begin.\n";
    cout << "1. Start a New File.\n";
    cout << "2. Display File List.\n";
    cout << "3. Open File. \n";
    cout << "4. Exit program.\n";
    cout << "Enter Selection: ";
    cin >> selection;
    //the switch navigates through the program.
    switch (selection)
    {
    case 1: //call openNewFile function
        openNewFile();
        break;
    case 2://call displayFiles function
        displayFiles();
        break;
    case 3://call openTextFile function
        openTextFile();
        break;    
    default: //shut down the program.
        break;
    }

    } while (selection != 4);

}

void TextEditor::openNewFile() {
    string fileName;
    string directory = "./TextEditorFiles";
    
    cout << "Filename: ";
    cin >> fileName;
    string filepath = directory + "/" + fileName + ".txt";
    ofstream newFile(filepath);
    textFiles.push_back(fileName +".txt");
    TextFile txtfile(fileName);//call TextFile constructor.
    //call editFile function on the new file.
    //newFile.editFile(fileName);    
}

void TextEditor::loadTextFiles(const string &directorypath){
    
    for (const std_filesystem::directory_entry& entry : std_filesystem::directory_iterator(directorypath))
    {
        if(entry.is_regular_file() && entry.path().extension() == ".txt"){
            textFiles.push_back(entry.path().filename().string());
        }
    }
}

void TextEditor::displayFiles(){
    cout << "Displaying files.\n";
    for(const string &fileName : textFiles){
        cout << fileName << endl;
    }
}

bool fileExt(string fileName){
        return fileName.substr(fileName.size() - 4) == ".txt"; 
    }

void TextEditor::openTextFile(){
    string fileName;
    string directory = "./TextEditorFiles";
    cout << "Enter filename to open. ";
    cin >> fileName;

    if(fileExt(fileName)== true) {
        ifstream file(directory+"/"+fileName);
        cout << fileName << endl;
        string line;

        while(getline(file, line)) {
            cout << line << endl;
            }
        } else {
            fileName = fileName + ".txt";
            ifstream file(directory+"/"+fileName);
            cout << fileName << endl;
            string line;

            while(getline(file, line)) {
            cout << line << endl;
            }
        }
    }