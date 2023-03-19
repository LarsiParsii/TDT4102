#include "std_lib_facilities.h"
#include <iostream>

void inputToFile(filesystem::path path)
{
    string nextWord;
    ofstream targetFile{path};
    
    while (cin >> nextWord)
    {
        if (nextWord == "quit")
        {
            break;
        }
        
        targetFile << nextWord << endl;
    }
    
    targetFile.close();
}

void addLineNumbersToFile(filesystem::path sourcePath)
{
    string nextLine;
    int lineNumber = 1;
    filesystem::path targetPath = "num_" + sourcePath.string();
    
    ifstream sourceFile{sourcePath};
    ofstream targetFile{targetPath};
    
    while (getline(sourceFile, nextLine))
    {
        targetFile << lineNumber << " " + nextLine << endl;
        lineNumber++;
    }
    
    sourceFile.close();
}