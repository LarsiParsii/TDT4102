#pragma once
#include "carddeck.h"

enum class Decision {hit, stand, invalid};    // More can be added (double down, split, surrender)
enum class Outcome  {bj, win, loss, bust, tie, invalid};

class Blackjack {
    private:
        // IDEA Create separate classes for players (if multiplayer)
        CardDeck deck;
        vector<Card> playerHand, dealerHand;
        int playerScore, dealerScore;

        void drawTestCard(vector<Card> &hand, Rank r);  // Only for testing/debugging
        
        void drawCardToHand(vector<Card> &hand);
        void moveCardToHand(vector<Card> &hand, Card c);
        void printHand(vector<Card> hand);
        int  getHandScore(vector<Card> hand);
        void updateScores(void);
        bool hasBlackjack(vector<Card> hand);
        Outcome getOutcome(vector<Card> playerHand, vector<Card> dealerHand);
        void printResult(Outcome outcome);
        Decision askPlayerDecision(void);
    
    public:
        Blackjack(void);
        void playGame(void);
};
