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

void inputIntegersAndPrintSum(void) {
    int sum = inputInteger() + inputInteger();
    cout << "Summen av tallene: " << sum << "\n" << endl;
}

bool isOdd(int num) {
    return num % 2 != 0;
}

void printHumanReadableTime(int seconds) {
    int hours = seconds / (60*60);    // 1 hour = 60 seconds * 60 minutes
    int minutes = (seconds % (60*60)) / 60;
    seconds = seconds % 60;
    cout << hours << " timer, " << minutes << " minutter, " << seconds << " sekunder\n" << endl;
}

void printSum(int count) {
    int sum = 0;
    for(int i = 0; i < count; i++) {
        sum += inputInteger();
    }
    cout << "Sum av " << count << " tall: " << sum << "\n" << endl;
}

void printUntilZero(void) {
    int sum = 0;
    int input = 0;
    do {
        input = inputInteger();
        sum += input;
    } while(input != 0);
    cout << "Summen av tallene: " << sum << endl;
}

double inputDouble(void) {
    double number;
    cout << "Skriv inn et desimaltall: ";
    cin >> number;
    return number;
}

void convertNOKtoEUR(void) {
    double nok = inputDouble();
    while (nok < 0) {
        cout << "Tallet kan ikke vaere negativt. \nSkriv inn et nytt tall: ";
        nok = inputDouble();
    }
    double eur = nok * 9.75;
    cout << setprecision(2) << fixed << nok << " NOK er " << eur << " EUR\n" << endl;
}
void printTimesTable(int width, int height) {
    for(int i = 1; i <= height; i++) {
        for(int j = 1; j <= width; j++) {
        cout << setw(4) << (i * j);
    }
        cout << endl;
    }
}

int main() {
    while (run) {
        cout << "\nVelg funksjon: \n" <<
                "0) Avslutt \n" <<
                "1) Skriv og print heltall \n" <<
                "2) Returner heltall \n" <<
                "3) Print sum av input \n" <<
                "4) Sjekk oddetall \n" << 
                "5) Sekunder til tekst \n" <<
                "6) Sum av n tall \n" <<
                "7) Sum av tall inntil stopp \n" <<
                "8) Returner desimaltall \n" <<
                "9) NOK til EUR \n" <<
                "10) Returner gangetabell \n" << endl;
        cout << "Angi valg (0-9): ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
        case 0:
            // Quit
            run = false;
            break;
        case 1:
            inputAndPrintInteger();
            break;
        case 2: {
            int number = inputInteger();
            cout << "Du skrev: " << number << endl;
            break; }
        case 3:
            inputIntegersAndPrintSum();
            break;
        case 4:
            for(int num = 0; num <= 15; num++) {
                cout << (isOdd(num) ? "true" :  "false") << "\n";
            }
            cout << endl;
            break;
        case 5:
            printHumanReadableTime(inputInteger());
            break;
        case 6:
            cout << "Angi antall tall som skal adderes: ";
            printSum(inputInteger());
            break;
        case 7:
            printUntilZero();
            break;
        case 8:
            cout << "Du skrev: " << inputDouble() << endl;
            break;
        case 9:
            convertNOKtoEUR();
            break;
        case 10:
            printTimesTable(10, 10);
            break;
        default:
            // Not a valid number. Retry.
            cout << "Valg ma vaere mellom 0 og 9!\n" << endl;
            break;
        }

    }
    return 0;
}

/* 
Oppgave 1e)
Jeg valgte inputInteger fordi jeg ikke har behov for å printe tallet brukeren
akkurat skrev inn, men heller bruke input fra brukeren i en funksjon (addering), og så printe dette i terminalen.

Oppgave 2c)
I oppgave 2a) er for-løkken mest velegnet, da den skal kjøre ett visst antall ganger.
I oppgave 2b) er do-løkken best. Fordi den skal kjøre så lenge brukeren ikke skriver inn 0.
Do-løkken sjekker om input er null på slutten av hver iterasjon, og kjøres dermed minst en gang.

I oppgave 2e) var det naturlig å benytte inputDouble() fordi jeg ønsket å lese inn et desimaltall fra brukeren.
Funkjsonen returnerer ingenting, og har derfor returtype void.
*/