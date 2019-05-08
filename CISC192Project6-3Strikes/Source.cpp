//this program plays the game 3 strikes in which the user draws digits and guesses the order of the digit that makes up the car price while trying to avoi
//strike tokens.  If the user gets 3 strikes before the car prices is correctly revealed, the game is over
//written by Brent Kinney 5/10/19

#include <iostream>
#include <string>
#include <array>
#include <random>
#include <vector>
using namespace std;


int main()
{
	char choice = 'y';

	do
	{
		char place4 = '_', place3 = '_', place2 = '_', place1 = '_', place0 = '_';
		char play = 'p';
		int price = 35297;
		const char arrayPrice[5] = { '7','9','2','5','3' };
		int strikes = 0;
		int digitsPlaced = 0;
		int position = 0;
		vector<char> vectorDigit = { 'S', '3', '5', 'S', '2', 'S', '9', '7' };
		int topRange = 7;

		//print rules of the game
		std::cout << " *********** Welcome to Three Strikes Game ***********" << endl;
		std::cout << "      Pick a chip from a bag, the chip will contain" << endl;
		std::cout << "     a digit or a strike, if it's a digit then guess" << endl;
		std::cout << "      which position it belongs to the car's price" << endl;
		std::cout << "     PANEL   : _ _ _ _ _ <- this is the 0th position" << endl;
		std::cout << "     POSITION: 4 3 2 1 0" << endl;
		std::cout << " Accumulating three strikes will result in losing the game." << endl;
		std::cout << "~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~" << endl;
		std::cout << endl;
		std::cout << "The price of the Car is $35297" << endl;
		std::cout << "~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~" << endl;

		do
		{
			//check if user has correctly placed all digits
			if (digitsPlaced == 5)
			{
				std::cout << "Congrats, you won! You placed all 5 digits correctly.\n";
				std::cout << "The price of the car was: $" << price << "\n\n";
				break;
			}
			else
			{
				//ask user if they would like to draw a chip or quit
				std::cout << "Enter 'p' to pick a chip, or any other key to quit the game: ";
				std::cin >> play;
				if (play == 'p' || play == 'P')
				{
					//display the strikes hit, digits placed, and panel
					std::cout << "Strikes hit: " << strikes << endl;
					std::cout << "Digits placed: " << digitsPlaced << endl;
					std::cout << "     PANEL   :$" << place4 << " " << place3 << " " << place2 << " " << place1 << " " << place0 << endl;
					std::cout << "     POSITION: 4 3 2 1 0" << endl;
					std::cout << "~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~" << endl;

					//draw random number
					std::random_device rd;
					std::mt19937 rng(rd());
					std::uniform_int_distribution<int> uni(0, topRange);
					auto randomInteger = uni(rng);
					std::cout << "\n\n";
					
					//check if drawn item is a strike and if so, notify user and remove the strike from the 'bag'
					if (vectorDigit[randomInteger] == 'S')
					{
						std::cout << "You picked a strike!!" << endl;
						vectorDigit.erase(vectorDigit.begin() + randomInteger);
						topRange = topRange - 1;
						strikes++;
					}
					else
					{
						//if drawn item is a digit, display it and ask what position the user thinks it belongs in
						std::cout << "You picked the digit: " << vectorDigit[randomInteger] << endl;
						std::cout << "Which position do you think it is? " << endl;
						std::cin >> position;
						
						//if the user guesses incorrectly, let the user know
						if (vectorDigit[randomInteger] != arrayPrice[position])
						{
							std::cout << "Sorry, you guessed the wrong position." << endl;
						}
						
						//if the user is correct, display appropriate message and check which digit was placed so the panel message can be updated
						else
						{
							std::cout << "Correct! You guessed the right position" << endl;
							if (position == 0)
							{
								place0 = vectorDigit[randomInteger];
							}
							else if (position == 1)
							{
								place1 = vectorDigit[randomInteger];
							}
							else if (position == 2)
							{
								place2 = vectorDigit[randomInteger];
							}
							else if (position == 3)
							{
								place3 = vectorDigit[randomInteger];
							}
							else
							{
								place4 = vectorDigit[randomInteger];
							}
							//remove the placed digit from the 'bag'
							vectorDigit.erase(vectorDigit.begin() + randomInteger);
							topRange = topRange - 1;
							digitsPlaced++;

						}

					}
					//if the user has reached 3 strikes, the game is over.
					if (strikes == 3)
					{
						std::cout << "Sorry, you lost the game." << endl;
						std::cout << "The price of the car was: $" << price << endl;
						break;
					}
				}
			}
		} while (play == 'p' || play == 'P');

		//see if the user wants to continue and continue if desired
		std::cout << "\nWould you like to play again? (Y/N): ";
		std::cin >> choice;
		std::cout << endl << endl;

	} while (choice == 'y' || choice == 'Y');

	//display author of the program
	std::cout << "Programmed by Brent Kinney" << endl;

	std::cout << "Press [Enter] key to end..."; //prompt lets user know
	std::cin.ignore(256, '\n');
	std::cin.get();

	return 0;
}