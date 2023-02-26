#include "std_lib_facilities.h"
#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
    return startValue;
}
void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
}
void swapNumbers(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void printStudent(const Student student)
{
    cout << "Name: " << student.name << endl;
    cout << "Study program: " << student.studyProgram << endl;
    cout << "Age: " << student.age << endl;
}
void isInProgram(const Student student, const string program)
{
    if (student.studyProgram == program)
    {
        cout << student.name << " is in " << program << endl;
    }
    else
    {
        cout << student.name << " is not in " << program << endl;
    }
}
string randomizeString(int length, char min, char max)
{
    string randomString = "";
    for (int i = 0; i < length; i++)
    {
        randomString += (rand() % (max - min + 1) + min);
    }
    return randomString;
}