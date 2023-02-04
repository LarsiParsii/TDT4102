#include "std_lib_facilities.h"
bool run = true;    // Whether or not to run the program
int choice;

void inputAndPrintInteger(void) {
    int number;
    cout << "Skriv inn et tall: ";
    cin >> number;
    cout << "Du skrev: " << number << "\n" << endl;
}

int inputInteger(void) {
    int number;
    cout << "Skriv inn et tall: ";
    cin >> number;
    return number;
}


int main() {
    while (run) {
        cout << "Velg funksjon: \n0) Avslutt \n1) Skriv og print heltall \n" <<
                "2) Returner heltall \n3) FUNKSJON 3" << endl;
        cout << "Angi valg (0-3):";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
        case 0:
            // Quit
            run = false;
            break;
        case 1:
            // Function 1
            inputAndPrintInteger();
            break;
        case 2: {
            // Function 2
            int number = inputInteger();
            cout << "Du skrev: " << number << "\n" << endl;
            break; }
        case 3:
            // Function 3
            break;
        default:
            // Not a valid number retry.
            cout << "Valg ma vaere mellom 0 og 3!\n" << endl;
            break;
        }

    }
    return 0;
}