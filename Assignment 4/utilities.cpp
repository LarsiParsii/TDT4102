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
string readInputToString(int length, char min, char max)
{
    string input = "";
    while (true)
    {
        input = "";
        cout << "Enter a word containing characters between " << min << " and " << max
             << ", in order to create a string of length " << length << endl;
        cout << "Your input: ";
        cin >> input;
        
        if (input.length() != length)
        {
            cout << "Your string is not of length " << length << "! Try again.\n" << endl;
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                if (input[i] < min || input[i] > max)
                {
                    cout << "Your string contains characters outside the range " << min << " to " << max << "! Try again.\n" << endl;
                    break;
                }
                else if (i == length - 1)
                {
                    cout << "Your string is valid!" << endl;
                    return stringToLower(input);
                }
            }
        }
    }
}

string stringToLower(string input)
{
    string output = "";
    for (char i : input)
    {
        output += tolower(i);
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