#pragma once
#include "std_lib_facilities.h"

class CourseCatalog {
    private:
        map<string, string> courses;
    
    public:
        CourseCatalog(void);
        void CourseCatalog::addCourse(string courseCode, string courseName);
        void CourseCatalog::removeCourse(string courseCode);
        string CourseCatalog::getCourse(string courseCode);
        friend ostream& operator<<(ostream& os, const CourseCatalog& c);
};