#include "std_lib_facilities.h"
#include "file_functions.h"

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

void printLetterStats(filesystem::path path)
{
    char nextLetter;
    ifstream sourceFile{path};
    map<char, int> letterCount;

    // Initialize the map with a count of 0 for each letter
    for (char c = 'a'; c <= 'z'; c++)
    {
        letterCount.insert(std::make_pair(c, 0));
    }
    
    while (sourceFile >> nextLetter)
    {
        nextLetter = static_cast<char>(tolower(nextLetter));
        if (nextLetter >= 'a' && nextLetter <= 'z') letterCount.at(nextLetter)++;
    }

    cout << "Letter stats:" << endl;
    int counter = 0;
    for (const auto &letter : letterCount)
    {
        cout << letter.first << ": " << letter.second << "\t\t";
        counter++;
        if (counter % COLUMNS == 0)
        {
            cout << endl;
        }
    }
}