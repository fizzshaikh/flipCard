// Fizzah Shaikh and Justin Chen
// Project 2b
// Define the main function and execute program. Also includes definition
// of playFlip()

#include <iostream>
#include <cmath>
#include <vector>
#include <typeinfo>
#include "Deck.h"

double playFlip(Deck& currHand)
//Plays Flip game.
//The program first selects the top 24 cards from the shuffled deck.
//Then, read in user input to decide which card of the 24 to pick.
//Refuse repeat picks. Calculate running score based on rules given.
{
	double score = 0;
	int userInput, numCards = 24;
	std::vector<bool> v(25, false);

	while (1)
	{
		std::cout << "Print out deck for reference" << std::endl;
		std::cout << currHand << std::endl;

		std::cout << "Enter an integer value from 1 to " << numCards
			<<" to choose a card from." << std::endl;
		std::cout << "Entering a 0 will exit the game: ";

		//Accept userInput. Keep asking for input until qualifications
		//are satisfied
		do
		{
			std::cin >> userInput;

			//Check that userInput is within bounds
			if (userInput!=0 && (userInput < 0) || (userInput > 24))
			{
				std::cout << "The number you entered is out of range." 
					<< std::endl;
			}
			//userInput acceptable input
			else if (v[userInput])
			{
				std::cout << "This is a repeat card:" << std::endl;
				std::cout << currHand.getCard(userInput) << std::endl;
				std::cout << "Please enter a different number" << std::endl;
			}

		} while (userInput!=0 && (userInput < 0) || (userInput > 24) 
			|| (v[userInput]));

		//Exit game if userInput == 0
		if (userInput == 0)
			break;
		else
		{
			v[userInput] = true;
			//Account for one offset (start at 0)
			userInput -= 1;
			Card currCard = currHand.getCard(userInput);

			//Output which card user chose
			std::cout << "You picked this card: Card #" << userInput+1 << ": ";
			std::cout << currHand.getCard(userInput) << std::endl;

			// Calculate score based on project sheet
			switch (currCard.getValue())
			{
			case 1:
				score += 10;
				break;
			case 2:
				score = 0;
				break;
			case 3:
				score = 0;
				break;
			case 4:
				score = 0;
				break;
			case 5:
				score = 0;
				break;
			case 6:
				score = 0;
				break;
			case 7:
				score = score / 2;
			case 8:
				score += 0;
			case 9:
				score += 0;
			case 10:
				score += 0;
			case 11:
				score +=5;
				break;
			case 12:
				score +=5;
				break;
			case 13:
				score += 5;
				break;
			}

			if (currCard.getSuit() == 'H')
			{
				score++;
			}
		}

		std::cout << "Current Score: " << score << std::endl;
		std::cout << "The cards you've chosen so far: " << std::endl;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == true)
			{
				Card used = currHand.getCard(i-1);
				std::cout << "Card # " << i << ": " << currHand.getCard(i-1)
					<< std::endl;
			}
		}
		
		//Separate rounds of the game
		std::cout << "____________________________________________" 
			<< std::endl;
	}

	std::cout << "Your final score is: " << score << std::endl;
	return score;
}


int main()
//Main function
{
	int numShuffles = 5;

	// start a new deck
	std::cout << "Creating an initial deck..." << std::endl;
	std::cout << "Deck pre-shuffle: " << std::endl;
	Deck d("true");
	std::cout << d << std::endl;

	// Shuffle the deck
	for (int i = 1; i <= numShuffles; i++)
	{
		d.shuffle();
		std::cout << "Shuffled deck " << i << ": " << std::endl;
		std::cout << d << std::endl;
	}

	playFlip(d);

	return 0;
}