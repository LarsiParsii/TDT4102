#include "std_lib_facilities.h"
#include "blackjack.h"

void Blackjack::drawTestCard(vector<Card> &hand, Rank r)
{
    hand.push_back(Card(Suit::hearts, r));
    updateScores();
}

void Blackjack::drawCardToHand(vector<Card> &hand)
{
    hand.push_back(deck.drawCard());
    updateScores();
}

void Blackjack::moveCardToHand(vector<Card> &hand, Card c)
{
    hand.push_back(c);
    updateScores();
}

int Blackjack::getHandScore(vector<Card> hand)
{
    int score = 0;
    int acesCount = 0;
    for (Card card : hand)
    {
        score += card.getValue();
        if (card.getRank() == Rank::ace) acesCount++;
    }
    while (score > 21 && acesCount > 0)
    {
        score -= 10;
        acesCount--;
    }
    return score;
}

void Blackjack::updateScores(void)
{
    playerScore = getHandScore(playerHand);
    dealerScore = getHandScore(dealerHand);
}

Decision stringToDecision(const string &input)
{
    if (input == "hit")
    {
        return Decision::hit;
    }
    else if (input == "stand")
    {
        return Decision::stand;
    }
    else
    {
        return Decision::invalid;
    }
}

Decision Blackjack::askPlayerDecision(void)
{
    string input;
    Decision decision;
    do
    {
        cout << "Enter your decision (hit or stand): ";
        getline(cin, input);

        // Convert to lowercase to handle case-insensitive input
        transform(input.begin(), input.end(), input.begin(), [](unsigned char c)
                  { return tolower(c); });

        decision = stringToDecision(input);

        if (decision == Decision::invalid)
        {
            cout << "Invalid decision. Please try again." << endl;
        }
    } while (decision == Decision::invalid);

    return decision;
}

void Blackjack::printHand(vector<Card> hand)
{
    if (hand.size() < 1)
    {
        cout << "You don't have any cards at your hand (this shouldn't happen). \nERROR!!" << endl;
    }
    for (Card card : hand)
    {
        cout << card.toString() << '\n';
    }
}

    Blackjack::Blackjack(void)
{
    // Constructor routine
    playerScore = 0;
    dealerScore = 0;
    playerBJ = false;
    dealerBJ = false;
}

void Blackjack::playGame(void)
{
    /* Routine when a game is started with playGame() */
    deck.shuffle();
    
    // TODO Welcome message


    // Deal initial cards
    cout << "[DEALING INITIAL CARDS]" << endl;

    drawCardToHand(playerHand);     // IDEA Use a for loop for multiple players
    drawCardToHand(dealerHand);
    drawCardToHand(playerHand);
    Card hiddenCard = deck.drawCard();

    cout << "Dealer's open card:" << endl;
    printHand(dealerHand);
    cout << "-> Dealer's score: " << dealerScore << endl;

    cout << "\nYour cards:" << endl;
    printHand(playerHand);
    cout << "-> Your score: " << playerScore << endl;
    cout << endl;


    // TODO Player's turn
    if (playerScore == 21) // Check for Blackjack (21 on initial cards)
    {
        cout << "Congratz, you got Blackjack! You win." << endl;
    }

    while (playerScore < 21)
    {
        Decision decision = askPlayerDecision();
        cout << "--------------------" << endl;

        if (decision == Decision::hit)
        {
            drawCardToHand(playerHand);
            
            cout << "\nYour cards:" << endl;
            printHand(playerHand);

            cout << "\n-> Your score: " << playerScore << endl;
            cout << endl;

            if (playerScore > 21) // Check for bust (over 21)
            {
                cout << "Bust! Game over." << endl;
            }
        }
        
        else if (decision == Decision::stand)
        {
            break;
        }
    }


    // TODO Dealer's turn
    moveCardToHand(dealerHand, hiddenCard);     // Reveal dealer's hidden card
    
    cout << "\nDealer's cards:" << endl;
    printHand(dealerHand);
    cout << "-> Dealer's score: " << dealerScore << endl;

    while (dealerScore < 17)
    {
        drawCardToHand(dealerHand);

        cout << "\nDealer's cards:" << endl;
        printHand(dealerHand);
        cout << "-> Dealer's score: " << dealerScore << endl;
    }


    // TODO Calculate/present outcome, ask for new game
}