#pragma once
// Fizzah Shaikh and Justin Chen
// Algo project 2b
// Header file for Deck class
// The deck class stores card objects in order through a linked list of nodes
// Each node is a single card

#ifndef deck_h
#define deck_h

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Card.h"
#include "Node.h"

class Deck
{
public:
	Deck(std::string deckType);
	~Deck();
	void shuffle();
	Card getCard(int cardIdx);
	friend std::ostream& operator << (std::ostream& ostr, const Deck& d);

private:
	Node <Card>* topN;
	void replace(Node <Card>* rep);
	Node <Card>* deal();
};

#endif deck_h