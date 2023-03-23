#include "std_lib_facilities.h"
#include "blackjack.h"

int Blackjack::getHandScore(vector<Card> hand)
{
	int score = 0;
	int acesCount = 0;
	for (Card card : hand)
	{
		score += card.getValue();
		if (card.getRank() == Rank::ace)
			acesCount++;
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

void Blackjack::drawTestCard(vector<Card> &hand, Rank r)
{
	// Only to be used for testing/debugging purposes
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
}

bool Blackjack::hasBlackjack(vector<Card> hand)
{
	return getHandScore(hand) == 21 && hand.size() == 2;
}

Outcome Blackjack::getOutcome(vector<Card> playerHand, vector<Card> dealerHand)
{
	/*
				POSSIBLE OUTCOMES
	Player BJ			|	Dealer BJ			--> Tie		// TODO Implement insurance
	Player BJ			|	Dealer no BJ		--> Player wins (x2.5) BLACKJACK
	Player no BJ		|	Dealer BJ			--> Loss
	Player busts		|	-					--> Bust
	Player no BJ/bust	|	Dealer bust			--> Win
	Player score same as dealer score			--> Tie
	Player no BJ/bust	|	Dealer no BJ/bust	--> Highest score wins
	*/

	int playerHandScore = getHandScore(playerHand);
	int dealerHandScore = getHandScore(dealerHand);

	if (hasBlackjack(playerHand))
	{
		return hasBlackjack(dealerHand) ? Outcome::tie : Outcome::bj;
	}
	else if (hasBlackjack(dealerHand))
	{
		return Outcome::loss; // Dealer has BJ
	}
	else if (playerHandScore > 21)
	{
		return Outcome::bust;
	}
	else if (dealerHandScore > 21)
	{
		return Outcome::win;
	}
	else if (playerHandScore == dealerHandScore)
	{
		return Outcome::tie; // Both have same score
	}
	else
	{
		return playerHandScore > dealerHandScore ? Outcome::win : Outcome::loss; // Highest score wins
	}
}

void Blackjack::printResult(Outcome outcome)
{
	switch (outcome)
	{
	case Outcome::bj:
		cout << "Congratz, you got Blackjack! Payout: x1.5" << endl;
		break;

	case Outcome::win:
		cout << "Congratz, you win! Payout: 1x" << endl;
		break;

	case Outcome::loss:
		cout << "You lost! Game over." << endl;
		break;

	case Outcome::bust:
		cout << "You bust! Game over." << endl;
		break;

	case Outcome::tie:
		cout << "It's a push! You get your wager back." << endl;
		break;

	default:
		cout << "[ERROR] The outcome is in an invalid state." << endl;
		break;
	}
}
