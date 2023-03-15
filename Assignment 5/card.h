#pragma once
#include "std_lib_facilities.h"

enum class Suit {spades, hearts, diamonds, clubs};
enum class Rank
{
    two = 2,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace
};

// PROTOTYPES
string suitToString(Suit suit);
string rankToString(Rank rank);

// CLASSES
class Card {
    private:
        Suit s;
        Rank r;
    public:
        Card(Suit suit, Rank rank);
        string getSuit(void);
        string getRank(void);
        string toString(void);
        int getValue(void);
};


/* TEORI
1e)
    En fordel ved å benytte symboler framfor strenger og tall er at det er lettere å lese og forstå koden.
    En annen fordel er at det gjør det umulig å velge feil verdi, da man kun kan velge mellom de som er definert i enum.
*/