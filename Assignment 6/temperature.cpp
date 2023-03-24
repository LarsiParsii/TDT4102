#include "std_lib_facilities.h"
#include "temperature.h"

istream &operator>>(istream &is, Temps &t)
{
	string max, min;
	getline(is, max, '\t');
	getline(is, min);

	t.max = stod(max);
	t.min = stod(min);

	return is;
}

vector<Temps> readTemps(filesystem::path path)
{
	ifstream sourceFile{path};
	vector<Temps> tempVector;
	string nextLine;

	while (getline(sourceFile, nextLine))
	{
		Temps t;
		stringstream ss(nextLine);
		
		ss >> t;
		tempVector.push_back(t);
	}
	return tempVector;
}

void tempStats(vector<Temps> tempVector)
{
	pair<int, double> hottestDay(-1,-300);	// Physically impossible
	pair<int, double> coldestDay(-1, 300);	// Hopefully impossible
	int index = 1;
	
	for (Temps t : tempVector)
	{
		if (t.max > hottestDay.second)
		{
			hottestDay.first = index;
			hottestDay.second = t.max;
		}
		
		if (t.min < coldestDay.second)
		{
			coldestDay.first = index;
			coldestDay.second = t.min;
		}
		
		index++;
	}
	cout << "\n[Temperature stats]" << endl;
	cout << "The warmest day was day #" << hottestDay.first << ", with " << hottestDay.second << " C." << endl;
	cout << "The coldest day was day #" << coldestDay.first << ", with " << coldestDay.second << " C." << endl;
}

double roundDouble(double number, int precision)
// Ikke i bruk
{
	return static_cast<double>(static_cast<int>(number * pow(10, precision)) / pow(10, precision));
}
