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
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(min, max);
    string randomString = "";
    for (int i = 0; i < length; i++)
    {
        randomString += static_cast<char>(distribution(generator));
    }
    return randomString;
}
string readInputToString(unsigned length, char min, char max)
{
    string input = "";
    while (true)
    {
        input = "";
        cin >> input;
        input = stringToUpper(input);
        
        if (input.length() != length)
        {
            cout << "\nYour string is not of length " << length << "! Try again." << endl;
        }
        else
        {
            for (unsigned i = 0; i < length; i++)
            {
                if (input[i] < min || input[i] > max)
                {
                    cout << "\nYour string contains characters outside the range "
                         << min << " to " << max << "! Try again." << endl;
                    break;
                }
                else if (i == length - 1)
                {
                    return input;
                }
            }
        }
    }
}
string stringToUpper(string input)
{
    string output = "";
    for (char c : input)
    {
        output += static_cast<char>(toupper(c));
    }
    return output;
}
int countChar(string input, char c)
{
    int count = 0;
    for (char i : input)
    {
        if (i == c)
        {
            count++;
        }
    }
    return count;
}