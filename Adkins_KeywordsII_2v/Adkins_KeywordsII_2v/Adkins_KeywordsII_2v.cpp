/*
Keywords II
Kieli Adkins
CSC215
May 30, 2018
*/

// Including standard libraries
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

// Including namespace std
using namespace std;

// Main function
int main()
{
	// // // // //
	//
	// Main title sequence
	//
	// // // // //

	// Username variable
	string userName;

	// Display title of program to user
	cout << "----------\nWelcome to Keywords II\n----------\n\n";

	// Ask the recruit to login using their name
	cout << "Please enter your name to begin: ";

	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cin >> userName;

	// Welcoming the recruit
	cout << "----------\nHello " << userName << "!\n----------\n\n";

	// Display an overview of what Keywords II is to the recruit 
	cout << "Keywords II, the successor to Keywords I, is a code breaking simulator that will be used to help prepare you for your position at the CIA.\n\n";

	// Display any directions to the recruit on how to use Keywords
	cout << "Your task, should you choose to accept it, is to correctly guess individual letters to find the secret code word.\n";
	cout << "In the beginning the word will consist of hyphens, this will show you how many letters are in the word.\n";
	cout << "As you correctly guess letters they will appear in place of these hyphens.\n";
	cout << "However, be careful as you only get 8 wrong guesses before you lose the simulation.\n\n\n";

	// // // // //
	//
	// Keywords
	//
	// // // // //

	// Create an int var to count the number of simulations being run starting at 1
	int sim = 0;

	// Defining play again variable
	char playAgain;

	// Beginning game loop
	do
	{
		// Increment the number of simulations ran counter6
		++sim;

		// Declaring a new vector
		vector<string> wordList;

		// Declaring the max amount of wrong guesses
		const int MAX_WRONG = 8;

		// Create a collection of 10 words you had wrote down manually
		wordList.push_back("SIREN");
		wordList.push_back("PHOENIX");
		wordList.push_back("HYDRA");
		wordList.push_back("ZEUS");
		wordList.push_back("DEMIGOD");
		wordList.push_back("HERCULES");
		wordList.push_back("VALKYRIE");
		wordList.push_back("OLYMPUS");
		wordList.push_back("LABYRINTH");
		wordList.push_back("POSEIDON");

		// Display the simulation # is staring to the recruit. 
		cout << "\n\n" << userName << ", this is simulation #" << sim << ".";

		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 

		for (int r = 0; r < 3; ++r)
		{
			// Seeding the random number generator
			srand(static_cast<unsigned int>(time(0)));

			// Randomly shuffling the keywords
			random_shuffle(wordList.begin(), wordList.end());

			// Word to guess
			const string THE_WORD = wordList[0];

			// Words guessed so far
			string soFar(THE_WORD.size(), '-');

			// Letters that have already been guessed
			string used = "";

			// Defining the guess variable
			char guess;

			// Number of incorrect guesses
			int wrong = 0;

			// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
			while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
			{
				// Tell recruit how many incorrect guesses he or she has left
				cout << "\n----------\n" << userName << ", you have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";

				// Show recruit the letters he or she has guessed
				cout << "You've used the following letters " << used << " .\n";

				// Show player how much of the secret word he or she has guessed
				cout << "So far the word is " << soFar << " .\n----------\n\n";

				// Printing the guess capture information
				cout << "\n----------\n" << userName << ", enter your guess: ";

				// Get recruit ’s guess
				cin >> guess;

				// Printing the guess capture information
				cout << "----------\n\n\n";

				// Capitalizing the player's guess
				guess = toupper(guess);

				//  While recruit has entered a letter that he or she has already guessed
				while (used.find(guess) != string::npos)
				{
					// Printing the already guessed information
					cout << "\nYou've already guessed " << guess;

					// Printing the guess capture information
					cout << "\n----------\n" << userName << ", enter your guess: ";

					// Get recruit ’s guess
					cin >> guess;

					// Printing the guess capture information
					cout << "----------\n\n\n";

					// Capitalizing the player's guess
					guess = toupper(guess);
				}

				// Add the new guess to the group of used letters
				used += guess;

				// If the guess is in the secret word
				if (THE_WORD.find(guess) != string::npos)
				{
					// Tell the recruit the guess is correct
					cout << "\nThat's right! " << guess << " is in the word.";

					// Update the word guessed so far with the new letter
					for (int i = 0; i < THE_WORD.length(); ++i)
					{
						// Adding the letter to the list 
						if (THE_WORD[i] == guess)
						{
							// Adding the letter to the soFar list
							soFar[i] = guess;
						}
					}
				}

				// Otherwise
				else
				{
					// Tell the recruit the guess is incorrect
					cout << "\nSorry, " << guess << " isn't in the word.";

					// Increment the number of incorrect guesses the recruit has made
					++wrong;
				}
			}

			// If the recruit has made too many incorrect guesses
			if (wrong == MAX_WRONG)
			{
				// Tell the recruit that he or she has failed the Keywords II course.
				cout << "\n\n----------\n" << userName << ", you have failed the Keywords II course, please contact instructor for further instructions.\n----------\n\n";
			}

			// Otherwise
			else
			{
				// Congratulate the recruit on guessing the secret words
				cout << "\n\n----------\nThe word was " << THE_WORD << ".\n\n----------\nYou have correctly guessed the keyword!\n----------\n\n";
			}
		}

		// Ask the recruit if they would like to run the simulation again
		cout << "\nIf you would like to play simulation again enter 'y', if not enter any other key to exit.\n";

		// Capturing play again variable
		cin >> playAgain;
	} 
	// While statement to end game loop
	while (playAgain != 'y' || playAgain != 'Y');

	// If the recruit wants to run the simulation again
	if (playAgain != 'y' || playAgain != 'Y')
	{
		// Increment the number of simulations ran counter
		++sim;

		// Move program execution back up to // Display the simulation # is staring to the recruit.
		cout << "\n\n" << userName << ", you are currently participating in simulation # " << sim << ".";
	}

	// Otherwise
	else
	{
		// Display End of Simulations to the recruit
		cout << "End of simulation";

		// Pause the Simulation with press any key to continue
		system("pause");
	}

	// Return to ensure program completion
	return 0;
}

