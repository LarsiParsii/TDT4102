#pragma once
#include "std_lib_facilities.h"

void testCourseCatalog(void);

class CourseCatalog {
	private:
		map<string, string> courses;
	
	public:
		CourseCatalog(void);
		friend ostream& operator<<(ostream& os, const CourseCatalog& c);
		void saveToFile(filesystem::path destinationPath);
		void loadFromFile(filesystem::path sourcePath);
		void addCourse(string courseCode, string courseName);
		void removeCourse(string courseCode);
		string getCourse(string courseCode);
};