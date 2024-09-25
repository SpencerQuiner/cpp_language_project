#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include "TextEditor.h"
using namespace std;

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
    case 1:
        /* code */
        break;
    case 2:
        /*code*/
        break;
    case 3:
        /*code*/
        break;    
    default:
        break;
    }

    } while (selection != 4);

}