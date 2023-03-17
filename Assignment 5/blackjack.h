#pragma once
#include "std_lib_facilities.h"
#include "card.h"
#include "carddeck.h"

enum class Decision {hit, stand, invalid};    // More can be added (double down, split, surrender)

class Blackjack {
    private:
        CardDeck deck;
        vector<Card> playerHand, dealerHand;
        int playerScore, dealerScore;
        bool playerBJ, dealerBJ;

        void drawTestCard(vector<Card> &hand, Rank r);
        
        void drawCardToHand(vector<Card> &hand);
        void moveCardToHand(vector<Card> &hand, Card c);
        void printHand(vector<Card> hand);
        int  getHandScore(vector<Card> hand);
        void updateScores(void);
        Decision askPlayerDecision(void);
    
    public:
        Blackjack(void);
        void playGame(void);
};