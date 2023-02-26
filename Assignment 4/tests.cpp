#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"

void testCallByValue(void)
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}
void testCallByReference(void)
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations << endl;
}
void testSwapByReference(void)
{
    int a = 5;
    int b = 10;
    cout << "a: " << a
         << " b: " << b << endl;
    cout << "Swapping..." << endl;
    swapNumbers(a, b);
    cout << "a: " << a
         << " b: " << b << endl;
}
void testPrintStudent(void)
{
    Student student = {"Lars", "Elektro", 22};
    printStudent(student);
}
void testIsInProgram(void)
{
    Student student = {"Lars", "Elektro", 22};
    isInProgram(student, "Elektro");
    isInProgram(student, "Data");
}
void testString(void)
{

}