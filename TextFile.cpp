//This file is to define the TextFile class declared in the TextEditor.H header file. 
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include "TextEditor.h"
using namespace std;
namespace std_filesystem = std::filesystem;

//TextFile constructor.
TextFile::TextFile(const string &fileName){
    this->fileName = fileName;
}


void TextFile::editFile(const string &fileName){
    fstream file(fileName, ios::in | ios::out); // Open the file for reading and writing
    
    string fileContent;
    string line;
    
    /* Read the file and display its contents
    cout << "Current contents of " << fileName << ":\n";
    fstream readFile(fileName , ios::in); // Use a separate stream to read the file
    while (getline(readFile, line)) {
        fileContent += line + "\n";
        cout << line << endl;
    }
    readFile.close();*/

    cout << "------type \"exit\" on a new line to quit editing.-------";

    while (true) {
        string newText;
        cout << "> ";  // Prompt for user input

        getline(cin, newText);

        // If the user types "exit", end the editing session
        if (newText == "exit") {
            cout << "Saving and Closing File.\n";
            break;
        }

        // Append the entered text to the file
        file << newText << endl;
    }

    // Close the file after editing
    file.close();
}


void TextFile::deleteFile(const string &fileName){
    // Check if the file exists before attempting to delete
    if (std_filesystem::exists(fileName)) {
        // Attempt to delete the file
        if (std_filesystem::remove(fileName)) {
            std::cout << "File deleted successfully: " << fileName << std::endl;
        } else {
            std::cerr << "Error deleting the file: " << fileName << std::endl;
        }
    } else {
        std::cout << "File does not exist: " << fileName << std::endl;
    }
}

void TextFile::fileMenu(const string &fileName){
    int selection = 0;
    cout << "What you would like to do.\n";
    cout << "1. Edit File.\n";
    cout << "2. Delete File.\n";
    cout << "3. Return to Main Menu.\n";
    cout << "Enter Selection: ";
    cin >> selection;

    switch (selection)
    {
    case 1:
        editFile(fileName);
        break;
    case 2:
        deleteFile(fileName);
    
        break;   
    default:
        break;
    }


}


