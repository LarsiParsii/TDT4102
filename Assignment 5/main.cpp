#include "std_lib_facilities.h"
#include "card.h"
#include "carddeck.h"
#include "blackjack.h"

int main()
{
    CardDeck d;
    d.print();

    Rank test1 = Rank::jack;
    Rank test2 = Rank::queen;

    if (test1 == test2)
    {
        std::cout << "Enums are equal\n";
    }
    else
    {
        std::cout << "Enums are not equal\n";
    }
    return 0;
}