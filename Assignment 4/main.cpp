#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"

int main() {

    /*Replace all cases except number 0 with placeholders.*/
    
    char selection = '0';
    while (selection != 'q') {
        cout << "\nSelect a test to run or q to quit: " << endl;
        cout << "1) Test call by value" << endl;
        cout << "2) Test call by reference" << endl;
        cout << "3) Test swap" << endl;
        cout << "4) Print student info" << endl;
        cout << "5) Test student programme" << endl;
        cout << "6) testString()" << endl;
        cout << "7) Test random string" << endl;
        cout << "8) PLACEHOLDER" << endl;
        cout << "9) PLACEHOLDER" << endl;
        cout << "q) Quit" << endl;
        cin >> selection;
        cout << endl;
        switch (selection) {
            case '1':
                testCallByValue();
                break;
            case '2':
                testCallByReference();
                break;
            case '3':
                testSwapByReference();
                break;
            case '4':
                testPrintStudent();
                break;
            case '5':
                testIsInProgram();
                break;
            case '6':
                testString();
                break;
            case '7':
                testRandomizeString();
                break;
            case '8':
                cout << countChar("Hello world!", 'l') << endl;
                break;
            case '9':
                break;
            case 'q':
                cout << "Bye!" << endl;
                break;
            default:
                cout << "Invalid selection!" << endl;
                break;
        }
        // Don't proceed until user has pressed enter
        cout << "Press enter to continue...";
        cin.ignore();
        cin.get();
    }
    return 0;
}

/*
Teorispørsmål
1a) Jeg forventer at v0 vil bli 5, increment vil bli 2 og iterations vil bli 10. Result vil bli 25.
1e) swapNumbers() bør bruke referanser fordi hvis ikke ville man ikke endret selve variabelen.

2e) Feilmeldingen "error: redefinition of 'Student'" oppstår fordi headerfilen utilities.h
    blir inkludert to ganger, hvilket fører til at struct Student blir definert to ganger.
    For å fikse dette burde man bruke #pragma once i utilities.h.


*/
