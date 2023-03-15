#pragma once
#include "std_lib_facilities.h"
#include "card.h"
#include "carddeck.h"

class Blackjack {
    private:
        CardDeck deck;
        vector<Card> playerHand, dealerHand;
        int playerHandSum, dealerHandSum;
        void drawCardToHand(vector<Card> hand);
        void askPlayerDecision(void);
        int  getHandScore(vector<Card> hand);
    public:
        Blackjack();
};