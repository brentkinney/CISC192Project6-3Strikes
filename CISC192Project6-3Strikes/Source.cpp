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
		cout << " *********** Welcome to Three Strikes Game ***********" << endl;
		cout << "      Pick a chip from a bag, the chip will contain" << endl;
		cout << "     a digit or a strike, if it's a digit then guess" << endl;
		cout << "      which position it belongs to the car's price" << endl;
		cout << "     PANEL   : _ _ _ _ _ <- this is the 0th position" << endl;
		cout << "     POSITION: 4 3 2 1 0" << endl;
		cout << " Accumulating three strikes will result in losing the game." << endl;
		cout << "~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~" << endl;

		do
		{
			if (digitsPlaced == 5)
			{
				cout << "Congrats, you won! You placed all 5 digits correctly.\n";
				cout << "The price of the car was: $" << price << "\n\n";
				break;
			}
			else
			{
				cout << "Enter 'p' to pick a chip, or any other key to quit the game: ";
				cin >> play;
				if (play == 'p' || play == 'P')
				{
					cout << "Strikes hit: " << strikes << endl;
					cout << "Digits placed: " << digitsPlaced << endl;
					cout << "     PANEL   :$" << place4 << " " << place3 << " " << place2 << " " << place1 << " " << place0 << endl;
					cout << "     POSITION: 4 3 2 1 0" << endl;
					std::random_device rd;
					std::mt19937 rng(rd());
					std::uniform_int_distribution<int> uni(0, topRange);
					auto randomInteger = uni(rng);
					cout << "\n\n";
					if (vectorDigit[randomInteger] == 'S')
					{
						cout << "You picked a strike!!" << endl;
						vectorDigit.erase(vectorDigit.begin() + randomInteger);
						topRange = topRange - 1;
						strikes++;
					}
					else
					{
						cout << "You picked the digit: " << vectorDigit[randomInteger] << endl;
						cout << "Which position do you think it is? " << endl;
						cin >> position;
						if (vectorDigit[randomInteger] != arrayPrice[position])
						{
							cout << "Sorry, you guessed the wrong position." << endl;
						}
						else
						{
							cout << "Correct! You guessed the right position" << endl;
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
							vectorDigit.erase(vectorDigit.begin() + randomInteger);
							topRange = topRange - 1;
							digitsPlaced++;

						}

					}
					if (strikes == 3)
					{
						cout << "Sorry, you lost the game." << endl;
						cout << "The price of the car was: $" << price << endl;
						break;
					}
				}
			}
		} while (play == 'p' || play == 'P');

		//see if the user wants to continue and continue if desired
		cout << "\nWould you like to play again? (Y/N): ";
		cin >> choice;
		cout << endl << endl;

	} while (choice == 'y' || choice == 'Y');

	//display author of the program
	cout << "Programmed by Brent Kinney" << endl;

	cout << "Press [Enter] key to end..."; //prompt lets user know
	cin.ignore(256, '\n');
	cin.get();

	return 0;
}