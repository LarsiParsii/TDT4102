#include "std_lib_facilities.h"
#include "file_functions.h"

filesystem::path fileName{"task1.txt"};
filesystem::path grunnlovFile{"grunnlov.txt"};

const map<string, string> capitalsMap{
	{"Norway", "Oslo"},
	{"Sweden", "Stockholm"},
	{"Denmark", "Copenhagen"}};

string getCapital(const string &country)
{
	return capitalsMap.at(country);		// Endret til å bruke .at()
}

int main()
{
	// inputToFile(fileName);
	// addLineNumbersToFile(fileName);
    //printLetterStats(grunnlovFile);

	/*
	// Oppgave 2b)
	std::cout << "Capitals:" << std::endl;
	for (pair<const string, const string> elem : capitalsMap)
	{
		cout << getCapital(elem.first) << std::endl;
	}
	*/
	
	return 0;
}