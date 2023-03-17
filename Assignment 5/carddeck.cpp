#include "std_lib_facilities.h"
#include "carddeck.h"

CardDeck::CardDeck(void)
{
    // Create a deck of cardsn
    for (int i = 0; i < 4; i++) // 4 suits (spades, hearts, diamonds, clubs)
    {
        for (int j = 2; j < 15; j++) // 13 ranks (2-10, J, Q, K, A)
        {
            cards.push_back(Card(static_cast<Suit>(i), static_cast<Rank>(j)));
        }
    }
}

void CardDeck::swap(unsigned i, unsigned j)
{
    Card temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
}

void CardDeck::print(void)
{
    for (Card card : cards)
    {
        cout << card.toString() << '\n';
    }
}

void CardDeck::shuffle(void)
{
    random_device seed;
    default_random_engine randomGenerator(seed());
    

    // Fisher-Yates shuffle
    for (unsigned i = static_cast<unsigned>(cards.size()) - 1; i > 0; i--)
    {
        uniform_int_distribution<unsigned> indexes(0, i + 1);
        
        unsigned j = static_cast<unsigned>(indexes(randomGenerator)) % (i + 1);
        swap(i, j);
    }
}

Card CardDeck::drawCard(void)
{
    Card c = cards.back();
    cards.pop_back();
    return c;
}