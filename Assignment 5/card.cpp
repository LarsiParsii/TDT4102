#include "std_lib_facilities.h"
#include "card.h"

string suitToString(Suit suit)
{
    //Use map to convert suit to string
    map<Suit, string> suitMap;
    suitMap[Suit::spades] = "Spades";
    suitMap[Suit::hearts] = "Hearts";
    suitMap[Suit::diamonds] = "Diamonds";
    suitMap[Suit::clubs] = "Clubs";
    return suitMap[suit];
}

string rankToString(Rank rank)
{
    //Use map to convert rank to string
    map<Rank, string> rankMap;
    rankMap[Rank::two] = "Two";
    rankMap[Rank::three] = "Three";
    rankMap[Rank::four] = "Four";
    rankMap[Rank::five] = "Five";
    rankMap[Rank::six] = "Six";
    rankMap[Rank::seven] = "Seven";
    rankMap[Rank::eight] = "Eight";
    rankMap[Rank::nine] = "Nine";
    rankMap[Rank::ten] = "Ten";
    rankMap[Rank::jack] = "Jack";
    rankMap[Rank::queen] = "Queen";
    rankMap[Rank::king] = "King";
    rankMap[Rank::ace] = "Ace";
    return rankMap[rank];
}

Card::Card(Suit suit, Rank rank) : s{suit}, r{rank} {};

string Card::getSuit(void)
{
    return suitToString(s);
}

string Card::getRank(void)
{
    return rankToString(r);
}

string Card::toString(void)
{
    return rankToString(r) + " of " + suitToString(s);
}

int Card::getValue(void)
{
    int value = static_cast<int>(r);
    if (value == 14)        // Ace
    {
        return 11;
    }
    else if (value > 10)    // Picture cards (jack, queen, king)
    {
        return 10;
    }
    else                    // All other cases (enum rank matches card value)
    {
        return value;
    }
}