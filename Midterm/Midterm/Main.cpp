#include <iostream>
#include <string>
using namespace std;

bool apple = 0; //adds ~ 10 health
bool key = 0; //needed to finish game
bool goldenapple = 0; //adds ~ 60 health
bool sword = 0; //fite them guardz

int main() {

	char input = 'a';
	int room = 1;
	string inventory[3]{ apple, key, goldenapple, sword }

	for (int i = 0; i < 3; i++)
		inventory[i] = " ";

	while (input != 'q') {
		switch (room) {
		case 1:
			cout << "welcome! you're in room 1! you can go south(s)!";
			cin >> input;
			if (input == 's')
				room = 2;
			else
				cout << "invalid input" << endl;
			break;

		case 2:
			cout << "you're in room 2, where you found an apple! you can go east(e)!";
			cin >> input;
			if (input == 'e')
				room = 3;
			break;

		case 3:
			cout << "you're in room 3! you can go east (e) or west (w)!";
			cin >> input;
			if (input == 'e')
				room = 4;
			if (input == 'w')
				room = 2;
			break;

		case 4:
			cout << "you're in room 4, where you found a key! you can go west (w) or south (s)!";
			cin >> input;
			if (input == 'w')
				room = 3;
			if (input == 's')
				room = 5;
			break;

		case 5:
			cout << "you're in room 5! you can go north(n) or south (s)!";
			cin >> input;
			if (input == 'n')
				room = 4;
			if (input == 's')
				room = 6;
			break;

		case 6:
			cout << "you're in room 6! you can go north(n) or west (w)!";
			cin >> input;
			if (input == 'n')
				room = 5;
			if (input == 'w')
				room = 7;
			break;

		case 7:
			cout << "you're in room 7! you can go west (w) or east (e)!";
			cin >> input;
			if (input == 'w')
				room = 8;
			if (input == 'e')
				room = 6;
			break;

		case 8:
			cout << "you're in room 8! you can go south (s) or east (e)!";
			cin >> input;
			if (input == 's')
				room = 9;
			if (input == 'e')
				room = 7;
			break;

		case 9:
			cout << "you're in room 9! you can go north (n) or south (s)!";
			cin >> input;
			if (input == 'n')
				room = 8;
			if (input == 's')
				room = 10;
			break;

		case 10:
			cout << "you're in room 10! you see a door that needs a key!";
			cin >> input;
			if (input == 'n')
				room = 1;
			if (input == 'w')
				room = 5;
			break;
		}
	}
}