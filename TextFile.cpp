//This file is to define the TextFile class declared in the TextEditor.H header file. 
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include "TextEditor.h"
using namespace std;

//TextFile constructor.
TextFile::TextFile(const string &fileName){
    this->fileName = fileName;
    this->createdDate = time(0); //set created date as current date.
    this->lastEdit = createdDate; // initial lastEdit date is the same as createdDate.

}

void TextFile::editFile(const string &fileName){

}

void TextFile::saveFile(const string &fileName){

}

void TextFile::deleteFile(const string &fileName){

}

