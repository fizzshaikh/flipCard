// Fizzah Shaikh and Justin Chen
// Project 2b
// Header for Card Class

#pragma once
#ifndef Card_h
#define Card_h

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <array>

class Card
{
private:
	int value;
	char suit;

public:
	Card(int v, char s);
	Card(const Card& t);
	void setValue(int value);
	void setSuit(char suit);
	int getValue() const;
	char getSuit() const;
	friend std::ostream& operator<< (std::ostream& ostr, const Card& t);
	Card& operator= (const Card& t);
};

#endif Card_h