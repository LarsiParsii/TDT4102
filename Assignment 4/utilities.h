#pragma once

// Structs
struct Student
{
    string name;
    string studyProgram;
    int age;
};

// Prototypes
int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
void swapNumbers(int& num1, int& num2);
void printStudent(const Student student);
void isInProgram(const Student student, const string program);
string randomizeString(int length, char min, char max);
string readInputToString(int length, char min, char max);
string stringToLower(string input);
int countChar(string input, char c);