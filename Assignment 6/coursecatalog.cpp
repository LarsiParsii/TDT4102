#include "std_lib_facilities.h"
#include "coursecatalog.h"

CourseCatalog::CourseCatalog(void)
{
}

ostream &operator<<(ostream &os, const CourseCatalog &c)
{
	for (pair<const string, const string> course : c.courses)
	{
		os << course.first << " " << course.second << endl;
	}
	return os;
}

void CourseCatalog::saveToFile(filesystem::path destinationPath)
{
	ofstream destinationFile{destinationPath};
	for (pair<const string, const string> course : courses)
	{
		destinationFile << course.first << "," << course.second << endl;
	}
}

void CourseCatalog::loadFromFile(filesystem::path sourcePath)
{
	string nextLine;
	ifstream sourceFile{sourcePath};
	while (getline(sourceFile, nextLine))
	{
		stringstream ss(nextLine);
		string courseCode, courseName;

		getline(ss, courseCode, ',');
		getline(ss, courseName);

		addCourse(courseCode, courseName);
	}
}

void CourseCatalog::addCourse(string courseCode, string courseName)
{
	courses[courseCode] = courseName;
	// Firkantparantes funker best her da den vil oppdatere en allerede eksisterende verdi
	// og opprette en ny hvis nøkkelen ikke finnes fra før av.
}

void CourseCatalog::removeCourse(string courseCode)
{
	courses.erase(courseCode);
}

string CourseCatalog::getCourse(string courseCode)
{
	return courses.at(courseCode);
}

void testCourseCatalog(void)
{
	CourseCatalog catalog;
	cout << "\n\nContent after adding courses:" << endl;
	catalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
	catalog.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
	catalog.addCourse("TMA4100", "Matematikk 1");
	cout << catalog;

	cout << "\nContent after editing C++ course:" << endl;
	catalog.addCourse("TDT4102", "C++");
	cout << catalog;

	cout << "\n[Saving courses to file]" << endl;
	catalog.saveToFile("savedcourses.txt");
	
	cout << "\nContent after removing all courses:" << endl;
	catalog.removeCourse("TDT4110");
	catalog.removeCourse("TDT4102");
	catalog.removeCourse("TMA4100");
	cout << catalog;

	cout << "\n[Loading courses from file]" << endl;
	cout << "\nContent after loading courses from file:" << endl;
	catalog.loadFromFile("savedcourses.txt");
	cout << catalog << endl;
}