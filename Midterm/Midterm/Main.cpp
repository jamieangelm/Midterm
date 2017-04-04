#include <iostream>
#include <string>
#include <ctime>
using namespace std;

bool apple = 0; //adds ~ 10 health
bool goldkey = 0; //key needed to finish game
bool goldenapple = 0; //adds ~ 60 health
bool sword = 0; //fite them guardz
bool silverkey = 0; //key to hidden room

void Monsters();

int main() {

	int num;

	string input = "a";
	int room = 1;
	string inventory[5];

	for (int i = 0; i < 5; i++)
		inventory[i] = " ";

	while (input.compare ("quit")!=0) {
		switch (room) {
		case 1:
			cout << "welcome! you're in room 1! you can go north or south!";
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 2;
			if (input.compare("south") == 0)
				room = 9;
			break;

		case 2:

			cout << "you're in room 2, where you found a silver key! you can go east or south!";
			getline(cin, input);
			if (input.compare("east") == 0)
				room = 3;
			if (input.compare("south") == 0)
				room = 1;

			for (int i = 0; i < 5; i++)
				inventory[0] = "silver key";
			system("pause");

			break;

		case 3:
			cout << "you're in room 3! you can go east or west!";
			getline(cin, input);
			if (input.compare("east") == 0)
				room = 4;
			if (input.compare("west") == 0)
				room = 2;
			break;

		case 4:
			cout << "you're in room 4, where you found a sword! you can go west or south!";
			getline(cin, input);
			if (input.compare ("west") == 0)
				room = 3;
			if (input.compare("south") == 0)
				room = 6;
			if (input.compare("north") == 0)
				room = 5;

			for (int i = 0; i < 5; i++)
				inventory[1] = "sword";
			system("pause");

			break;

		case 5:
			cout << "you're in room 5, where you encounter a monster!" << endl;
			Monsters();
				
			cout << "you can go south!" << endl;
			getline(cin, input);
			if (input.compare("south") == 0)
				room = 6;

			cout << "no" << endl;

			break;

		case 6:
			cout << "you're in room 6, where you encounter a monster! you can go north or south!";
			Monsters();
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 4;
			if (input.compare("south") == 0)
				room = 7;
			break;

		case 7:
			cout << "you're in room 7! you can go north and west!";
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 6;
			if (input.compare("west") == 0)
				room = 8;
			break;

		case 8:
			cout << "you're in room 8! you can go west or east!";
			getline(cin, input);
			if (input.compare("west") == 0)
				room = 9;
			if (input.compare("east") == 0)
				room = 7;
			break;

		case 9:
			cout << "you're in room 9, where you see a human! you can go north or south!";
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 1;
			if (input.compare("south") == 0)
				room = 10;
			break;

		case 10:
			cout << "you're in room 10, where you see a red apple! you can go north or south!";
			getline(cin, input);
			if (input.compare("northt") == 0)
				room = 9;
			if (input.compare("south") == 0)
				room = 11;

			for (int i = 0; i < 5; i++)
				inventory[2] = "red apple";
			system("pause");

			break;

		case 11:
			cout << "you're in room 11! you encounter a monster! you need a key to unlock the door!";
			Monsters();
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 10;
			if (input.compare("east") == 0)
				room = 12;
			break;

		case 12:
			cout << "you're in room 12! congratulations!";
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 1;
			if (input.compare("west") == 0)
				room = 5;
			break;
		}
	}
}

void Monsters() {

	int num = rand() % 100 + 1;
	if (num <= 50)
		cout << "A vampire appears and attacks you" << endl;
	else if (num > 51 && num <= 80)
		cout << "An alien appears and attacks you" << endl;
	else
		cout << "A zombie appears and attacks you" << endl;

}