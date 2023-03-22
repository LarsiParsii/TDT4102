#include <windows.h> // For Sleep() in Windows
#include "std_lib_facilities.h"
#include "blackjack.h"

void Blackjack::playGame(void)
{
    /* TODO
     * Add system for printing each seat's hand in "columns", in order
     * to give a better overview of all the cards in game.
     */

    /* Routine when a game is started with playGame() */
    deck.shuffle();
    Outcome outcome = Outcome::invalid;

    // TODO Welcome message

    // Deal initial cards
    cout << "[DEALING INITIAL CARDS]\n"
         << endl;

    drawCardToHand(playerHand); // IDEA Use a for loop for multiple players
    drawCardToHand(dealerHand);
    drawCardToHand(playerHand);
    Card hiddenCard = deck.drawCard();

    cout << "Dealer's open card:" << endl;
    printHand(dealerHand);
    cout << "-> Dealer's score: " << dealerScore << endl;

    cout << "\nYour cards:" << endl;
    printHand(playerHand);
    cout << "-> Your score: " << playerScore << endl;

    // TODO Player's turn
    if (playerScore == 21) // Check for Blackjack (21 on initial cards)
    {
        outcome = Outcome::bj;
    }
    
    else
    {
        while (playerScore < 21)
        {
            cout << "--------------------" << endl;
            Decision decision = askPlayerDecision();
            Sleep(250);

            if (decision == Decision::hit)
            {
                drawCardToHand(playerHand);

                cout << "\nYour cards:" << endl;
                printHand(playerHand);

                cout << "-> Your score: " << playerScore << "\t(Dealer has: " << dealerScore << ")" << endl;
            }

            else if (decision == Decision::stand)
            {
                break;
            }
            
            if (playerScore > 21)
            {
                outcome = Outcome::bust;
                break;
            }

            // IDEA Add cases for double down and split
        }
    }

    Sleep(2000);

    // TODO Dealer's turn
    cout << "----------------------------------------" << endl;

    // Reveal dealer's hidden card
    moveCardToHand(dealerHand, hiddenCard);
    cout << "\nDealer's cards:" << endl;
    printHand(dealerHand);
    cout << "-> Dealer's score: " << dealerScore  << "\t(You have: " << playerScore << ")"  << endl;

    while (dealerScore < 17 && outcome != Outcome::bj && outcome != Outcome::bust)
    {
        Sleep(2000);
        drawCardToHand(dealerHand);

        cout << "\nDealer's cards:" << endl;
        printHand(dealerHand);
        cout << "-> Dealer's score: " << dealerScore  << "\t(You have: " << playerScore << ")" << endl;
    }
    
    cout << "----------------------------------------" << endl;
    // TODO Calculate/present outcome, ask for new game
    
    outcome = getOutcome(playerHand, dealerHand);
    printResult(outcome);
    cout << endl;
    
    Sleep(5000);
}