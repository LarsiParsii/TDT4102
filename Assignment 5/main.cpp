#include "std_lib_facilities.h"
#include "card.h"
#include "carddeck.h"
#include "blackjack.h"

int main()
{
    cout << "\n--------------[ NEW GAME ]--------------\n" << endl;
    Blackjack game;
    game.playGame();

    return 0;
}