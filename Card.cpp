// Fizzah Shaikh and Justin Chen
// Project 2b
// Card class definition

#include "Card.h"

Card::Card(int v, char s)
// Initialize the card through constructor
{
	value = v;
	suit = s;
}

Card::Card(const Card& v)
// Overloaded Card constructor to set private values for the object
{
	value = v.value;
	suit = v.suit;
}

void Card::setValue(int v)
{
// Set value of card from user input
// Check if input value is within 1-13
	if (v < 1 || v > 13)
	{
		std::cout << "Unable to set card value. Invalid input." << std::endl;
		return;
	}
	value = v;
}


void Card::setSuit(char s)
// Set suit from user input
{
	// Check if input value is Ace, Jack, King, Queen
	char acceptedLetter[8] = { 'C', 'D', 'H', 'S', 'c', 'd', 'h', 's' };
	int acceptedLetterSize = sizeof(acceptedLetter) / sizeof(char);
	int idx = 0;
	bool flag = false;

	while (flag == false && idx < acceptedLetterSize)
	{
		if (s == acceptedLetter[idx])
			flag = true;
		idx++;
	}

	//Set new suit value
	if (flag == true)
	{
		suit = s;
	}
	//Do nothing. Output error message
	else
		std::cout << "Unable to set card suit. Invalid input." << std::endl;
}

int Card::getValue() const
// Return card value as int
{
	return value;
}

char Card::getSuit() const
// Return card suite as char
{
	return suit;
}

std::ostream& operator<< (std::ostream& ostr, const Card& t)
// Overloaded operator assigned to print card value
{
	//Get Card value
	int val = t.getValue();

	//Non facecard numbers
	if (val >= 2 && val <= 10)
	{
		ostr << "Value: " << val << ", Suit: " << t.getSuit();
	}
	else
	{
		// variable to store value if the value is not an int
		char charVal;

		// check if card value should be read out as letter
		switch (t.getValue())
		{
		case 1: // if value = 1
			charVal = 'A';
			break;

		case 11:
			charVal = 'J';
			break;

		case 12:
			charVal = 'Q';
			break;

		case 13:
			charVal = 'K';
			break;

		default:
			charVal = t.getValue();
		}

		ostr << "Value: " << charVal << ", Suit: " << t.getSuit();
	}

	return ostr;
}

Card& Card::operator= (const Card& t)
//Overload = operator to compare cards
{
	value = t.value;
	suit = t.suit;

	return *this;
}