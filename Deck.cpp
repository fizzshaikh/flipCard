// Fizzah Shaikh and Justin Chen
// Project 2b
// Define the Deck class with definitions for Deck, Shuffle,
// and overloads the << operator

#include "Deck.h"

Deck::Deck(std::string deckType)
//Deck object constructor
{
	// point to null at first
	topN = NULL;

	// random generator 
	srand(time(NULL));

	if (deckType.compare("true")==0)
	{
		//Initialize new deck
		for (int i = 1; i <= 13; i++)
		{
			//Clubs
			topN = new Node<Card>(Card(i, 'C'), topN);
			//Diamond
			topN = new Node<Card>(Card(i, 'D'), topN);
			//Heart
			topN = new Node<Card>(Card(i, 'H'), topN);
			//Spade
			topN = new Node<Card>(Card(i, 'S'), topN);
		}
	}
}

Deck::~Deck()
//Deck deconstructor
{
	std::cout << "Destructing deck..." << std::endl;
	Node <Card>* curr = topN;
	Node <Card>* temp;

	// Delete each curr node until you reach the end of the list
	while (curr != NULL)
	{
		temp = curr->next;
		delete curr;
		curr = NULL;
		curr = temp;
	}
}
void Deck::shuffle()
//Shuffles the deck shuffleTimes times
{
	int currIdx = 0, shuffleTimes = 10000, targetCardIdx = 0;

	Node <Card> *curr;
	Node <Card> *prev;
	Node <Card> *last = topN;
	Node <Card> *switchedCard;
	curr = topN;
	prev = topN;
	switchedCard = topN;

	//Find last node
	while (last->next != NULL)
	{
		last = last->next;
	}
	//last is now last card in deck

	//Move a card to the last position shuffleTimes times
	for (int i = 0; i <= shuffleTimes; i++)
	{
		//Reset currIdx, prev and curr pointers
		currIdx = 0;
		prev = topN;
		curr = topN;

		//Choose a random number from 0-51, representing the 
		//index of each of the 52 cards
		targetCardIdx = std::rand() % 51;

		//Account for case of targetCardidx == 51 (tail)
		if (targetCardIdx == 51)
		{
			//Go next
			break;
		}
		//Account for case of targetCardIdx == 0 (head)
		else if (targetCardIdx == 0)
		{
			//Create copy of topN
			switchedCard = topN;
			//Reassign topN to second card
			topN = topN->next;
			//switchedCard next should be NULL
			switchedCard->next = NULL;
			//copy becomes last
			last->next = switchedCard;
			last = last->next;
		}
		//General case
		else
		{
			//Find the card at one before the target index, prev
			while (currIdx != targetCardIdx -1)
			{
				prev = prev->next;
				currIdx++;
			}

			//Find the card at target index, switchedCard
			curr = prev->next;

			//Previous card point to next card
			prev->next = prev->next->next;

			//Tail point to curr, curr point to NULL
			last->next = curr;
			last = last->next;
			last->next = NULL;
		}
	}
}

Card Deck::getCard(int cardIdx)
//Returns Card object at cardIdx in Deck
{
	int currIdx = 0;
	Node <Card> *curr;
	curr = topN;

	while (currIdx != cardIdx)
	{
		curr = curr->next;
		currIdx++;
	}

	return curr->nodeValue;
}

Node <Card>* Deck::deal()
//Returns top Card in deck. Also removes Card from deck
{
	// create current node to return		
	Node <Card>* curr;
	// point current to top of deck		
	curr = topN;
	// point front node to the next card in deck		
	topN = topN->next;
	// return top card		
	return curr;
}

void Deck::replace(Node <Card>* rep)
// Place a card on bottom of deck		
{
	// make node to point to front		
	Node <Card>* back = topN;

	// make the next of the replacement card to NULL		
	rep->next = NULL;

	// if the list is empty, make the front card = the replacement		
	if (topN == NULL)
	{
		topN = rep;
		return;
	}

	// iterate through the list until you're at the last node		
	while (back->next != NULL)
		back = back->next;

	// make the last node = the card as a parameter		
	back->next = rep;
}

std::ostream& operator << (std::ostream& ostr, const Deck& d)
//Overloaded << operator to print the entire deck
{
	//Point to the front of the deck
	Node <Card>* curr;
	curr = d.topN;
	int count = 1;
	// loop through deck until pointing to null
	while (curr!=NULL)
	{
		ostr << "Card #" << count<< ": " << curr->nodeValue << std::endl;
		curr = curr->next;
		count++;
	}
	return ostr;
}