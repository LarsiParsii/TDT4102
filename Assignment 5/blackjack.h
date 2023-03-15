#pragma once
#include "std_lib_facilities.h"
#include "card.h"
#include "carddeck.h"

class Blackjack {
    private:
        CardDeck deck;
        vector<Card> playerHand, dealerHand;
        int playerHandSum, dealerHandSum;
        
        void addToHand(vector<Card> hand);
        int getHandScore(vector<Card> hand);
    
    public:
        Blackjack();
};