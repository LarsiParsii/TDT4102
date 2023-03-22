#include "std_lib_facilities.h"
#include "file_functions.h"

filesystem::path fileName{"task1.txt"};
filesystem::path grunnlovFile{"grunnlov.txt"};

int main()
{
    //inputToFile(fileName);
    //addLineNumbersToFile(fileName);
    printLetterStats(grunnlovFile);
    return 0;
}