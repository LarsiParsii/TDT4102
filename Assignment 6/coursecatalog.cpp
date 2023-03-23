#include "std_lib_facilities.h"
#include "coursecatalog.h"

CourseCatalog::CourseCatalog(void)
{
}

void CourseCatalog::addCourse(string courseCode, string courseName)
{
    courses.insert({courseCode, courseName});
}

void CourseCatalog::removeCourse(string courseCode)
{
    courses.erase(courseCode);
}

string CourseCatalog::getCourse(string courseCode)
{
    return courses.at(courseCode);
}

ostream& operator<<(ostream& os, const CourseCatalog& c)
{
    for (pair<const string, const string> elem : c.courses)
    {
        os << elem.first << " " << elem.second << endl;
    }
    return os;
}