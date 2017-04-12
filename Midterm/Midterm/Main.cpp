//Jamie Martinez, April 12
//Game Name: 

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int health = 500; //total health

bool redapple = 50; //adds ~ 50 health
bool goldkey = 0; //key needed to finish game
bool goldenapple = 350; //adds ~ 350 health
bool sword = 0; //fight monsters
bool bronzekey = 0; //to other hidden room from human
bool silverkey = 0; //key to hidden room
bool goldenartifact = 0; //wins game

void Monsters();

int main() {

	int num;

	string input = "a";
	int room = 1;
	string inventory[5];  //going into rooms

	for (int i = 0; i < 5; i++)
		inventory[i] = " ";

	cout << "You feel the eerie atmosphere as you approach 'The Labyrinth'..." << endl; //introduction to the game

	while (input.compare ("quit")!=0) {
		switch (room) {
		case 1:  //room 1
			system("Color 1C");
			cout << "You enter a room that's barely lit with a few torches. You can go north or south.";
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 2;
			if (input.compare("south") == 0)
				room = 9;
			break;

		case 2:  //room 2
			cout << "You enter a more lit room with a table, where you found a silver key! You pick it up and decide if you want to go east or south.";
			getline(cin, input);
			system("Color 2B");
			if (input.compare("east") == 0)
				room = 3;
			if (input.compare("south") == 0)
				room = 1;

			for (int i = 0; i < 5; i++)
				inventory[0] = "silver key";

			break;

		case 3:  //room 3
			cout << "you're in a room that has a lot of old, fragile, vases... nothing too interesting. You can go east or west.";
			getline(cin, input);
			system("Color 1C");
			if (input.compare("east") == 0)
				room = 4;
			if (input.compare("west") == 0)
				room = 2;
			break;

		case 4: //room 4
			cout << "you enter a small room, where you found a sword on the wall! You take it and debate on going west or south.";
			getline(cin, input);
			system("Color 2B");
			if (input.compare ("west") == 0)
				room = 3;
			if (input.compare("south") == 0)
				room = 6;
			if (input.compare("north") == 0)
				room = 5;

			for (int i = 0; i < 5; i++)
				inventory[1] = "sword";

			break;

		case 5: //room 5
			cout << "you've found and entered the secret room, where you encounter a monster." << endl;
			system("Color 4B");
			Monsters();
				
			cout << "you can go south!" << endl;
			getline(cin, input);
			if (input.compare("south") == 0)
				room = 6;

			for (int i = 0; i < 5; i++)
				inventory[0] = "gold key";

			break;

		case 6: //room 6
			cout << "The human exposed the second secret room, where he exposed you to a monster encounter.";
			Monsters();
			system("Color 4B");
			getline(cin, input);
			if (input.compare("west") == 0)
				room = 4;
			break;
			
		case 7:  //room 7
			cout << "you're in room 7, where you encounter a monster. You can go north or south";
			getline(cin, input);
			system("Color 2B");
			if (input.compare("north") == 0)
				room = 4;
			if (input.compare("south") == 0)
				room = 8;

			for (int i = 0; i < 5; i++)
				inventory[0] = "red apple";

			break;

		case 8:  //room 8
			cout << "you're in room 8! you can go west or north.";
			getline(cin, input);
			system("Color 1C");
			if (input.compare("west") == 0)
				room = 9;
			if (input.compare("north") == 0)
				room = 7;
			break;

		case 9:  //room 9
			cout << "you're in room 9! you can go west or east.";
			getline(cin, input);
			system("Color 1C");
			if (input.compare("west") == 0)
				room = 1;
			if (input.compare("east") == 0)
				room = 10;
			break;

		case 10:  //room 10
			cout << "you're in room 10, where you see a human! you can go north or south.";
			system("Color 3C");
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 9;
			if (input.compare("south") == 0)
				room = 11;

			for (int i = 0; i < 5; i++)
				inventory[2] = "red apple";

			break;

		case 11:  //room 11
			cout << "you're in room 11! you encounter a monster! you need a key to unlock the door.";

			system("Color 2B");
			Monsters();

			getline(cin, input);
			if (input.compare("north") == 0)
				room = 10;
			if (input.compare("east") == 0)
				room = 12;

			for (int i = 0; i < 5; i++)
				inventory[0] = "silver key";

			break;

		case 12:  //room 12
			cout << "you're in room 12! you encounter a monster!";
			getline(cin, input);
			system("Color 4B");
			if (input.compare("north") == 0)
				room = 1;
			if (input.compare("west") == 0)
				room = 5;
			break;

		case 13: //last room to win
			cout << "You reach the end, where you find the gold arifact! Congratulations on your journey!" << endl;
			system("Color 2B");

			for (int i = 0; i < 5; i++)
			inventory[0] = "goldenartifact";

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