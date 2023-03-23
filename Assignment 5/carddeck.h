#pragma once
#include "card.h"

class CardDeck {
    private:
        vector<Card> cards;
        void swap(size_t i, size_t j);    // Private as it is only used by the shuffle() function.
    public:
        CardDeck(void);
        void print(void);
        void shuffle(void); // Uses the Fisher-Yates shuffle algorithm together with the swap() function.
        Card drawCard(void);
};