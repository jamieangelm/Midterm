#include <iostream>
#include <string>
	using namespace std;

	bool redapple = 0; //adds ~ 10 health
	bool silverkey = 0; //key to hidden room
	bool goldkey = 0; //key to win game
	bool goldenapple = 0; //adds ~ 60 health
	bool sword = 0; //fite monsters

	int main() {

		char input = 'a';
		int room = 1;
		string inventory[3]{ redapple, silverkey, goldenapple, sword, goldkey }

		for (int i = 0; i < 3; i++)
			inventory[i] = " ";

		while (input != 'q') {
			switch (room) {
			case 1:
				cout << "you're in room 1! you can go north (n) or south(s)!";
				cin >> input;
				if (input == 'n')
					room = 2;
				if (input == 's')
					room = 8;
				else
					cout << "invalid input" << endl;
				break;

			case 2:
				cout << "you're in room 2, where you found a silver key! you can go east(e) or south (s)!";
				cin >> input;
				if (input == 'e')
					room = 3;
				if (input == 's')
					room = 1;
				else
					cout << "invalid input" << endl;
				break;

			case 3:
				cout << "you're in room 3! you can go east (e) or west (w)!";
				cin >> input;
				if (input == 'e')
					room = 4;
				if (input == 'w')
					room = 2;
				else
					cout << "invalid input" << endl;
				break;

			case 4:
				cout << "you're in room 4, where you find a sword! you can go west (w) or south (s)!";
				cin >> input;
				if (input == 'w')
					room = 3;
				if (input == 's')
					room = 5;
				else
					cout << "invalid input" << endl;
				break;

			case 5:
				cout << "you're in secret room 5, where a monster approaches you! attack it?";
				cin >> input;
				if (input == 'n')
					room = 9;
				if (input == 'e')
					room = 11;
				else
					cout << "invalid input" << endl;
				break;

			case 5:
				cout << "you're in room 5, where a monster approaches you! you can go north(n) or south (s)!";
				cin >> input;
				if (input == 'n')
					room = 4;
				if (input == 's')
					room = 6;
				else
					cout << "invalid input" << endl;
				break;

			case 6:
				cout << "you're in room 6! you can go north(n) or west (w)!";
				cin >> input;
				if (input == 'n')
					room = 5;
				if (input == 'w')
					room = 7;
				else
					cout << "invalid input" << endl;
				break;

			case 7:
				cout << "you're in room 7! you can go west (w) or east (e)!";
				cin >> input;
				if (input == 'w')
					room = 8;
				if (input == 'e')
					room = 6;
				else
					cout << "invalid input" << endl;
				break;

			case 8:
				cout << "you're in room 8! you can go north (n), south (s) or east (e)!";
				cin >> input;
				if (input == 'n')
					room = 1;
				if (input == 's')
					room = 9;
				if (input == 'e')
					room = 7;
				else
					cout << "invalid input" << endl;
				break;

			case 9:
				cout << "you're in room 9, where you find a red apple! you can go north (n) or south (s)!";
				cin >> input;
				if (input == 'n')
					room = 8;
				if (input == 's')
					room = 10;
				else
					cout << "invalid input" << endl;
				break;

			case 10:
				cout << "you're in room 10, where a monster approaches you! you can go north (n) or east (e)!";
				cin >> input;
				if (input == 'n')
					room = 9;
				if (input == 'e')
					room = 11;
				else
					cout << "invalid input" << endl;
				break;

			case 11:
				cout << "you're in room 11, where you see the exit! you beat the game";
				break;

			case 5:
				cout << "you're in room 5, where a monster approaches you! attack it?";
				cin >> input;
				if (input == 'n')
					room = 9;
				if (input == 'e')
					room = 11;
				else
					cout << "invalid input" << endl;
				break;
			}
		}
	}