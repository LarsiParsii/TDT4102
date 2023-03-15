#include "std_lib_facilities.h"
#include "blackjack.h"

Blackjack::Blackjack()
{
    // Startup routine for new games
    deck.shuffle();

    // Deal initial cards
    
}

void Blackjack::drawCardToHand(vector<Card> hand)
{
    hand.push_back(deck.drawCard());
}

int Blackjack::getHandScore(vector<Card> hand)
{
    int score = 0;
    int acesCount = 0;
    for (Card card : hand)
    {
        score += card.getValue();
    }
    while (score > 21 && acesCount > 0)
    {
        score -= 10;
        acesCount--;
    }
    return score;
}

void Blackjack::askPlayerDecision(void)
{

}