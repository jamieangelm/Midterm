//Jamie Martinez, April 12
//Game Name: The Labyrinth

#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

int health = 500; //total health

ivenotry[0] = "fdf";

redapple //adds ~ 50 health
goldkey //key needed to finish game
goldenapple  //adds ~ 350 health
sword  //fight monsters
bronzekey  //to other hidden room from human
silverkey  //key to hidden room
goldenartifact  //wins game

void Monsters();

int main() { //begin main

	string input = "a";
	int room = 1;
	string inventory[6];  //7 items listed above

	cout << "You feel the eerie atmosphere as you approach 'The Labyrinth'..." << endl; //introduction to the game
	cout << "----------------------------------------------------------------" << endl; //make it spaced nice
	
	while (input.compare ("quit")!=0) { //begin while loop
		switch (room) { //begin switch
		case 1:  //room 1
			system("Color 1C"); //color for plain room
			cout << "You enter a room that's barely lit with a few torches. You can go north or south.";
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 2;
			else if (input.compare("south") == 0)
				room = 9;
			else
				cout << "invalid input" << endl;
			break;

		case 2:  //room 2
			cout << "You enter a more lit room with a table in the middle of the room";
			if (inventory[0] = ("silver key") //no silver key in inventory
				cout << "there's a silver key on the table" << endl; //say there's a key on the table
			getline(cin, input);
			if (input.compare("silver key") == 0) { //silver key is now in the inventory
				inventory[0] = "silver key"; //put in 
				cout << "You grabbed the key!" << endl;

				system("Color 2B"); //color for rooms with items

				cout << "You pick it up and decide if you want to go east or south." << endl;
				getline(cin, input);
				if (input.compare("east") == 0)
					room = 3;
				else if (input.compare("south") == 0)
					room = 1;
				else
					cout << "invalid input" << endl;

				inventory[0] = "silver key";

				break;

		case 3:  //room 3
			cout << "you're in a room that has a lot of old, fragile, vases... nothing too interesting. You can go east or west.";
			getline(cin, input);
			system("Color 1C"); //color for plain room
			if (input.compare("east") == 0)
				room = 4;
			if (input.compare("west") == 0)
				room = 2;
			break;

		case 4: //room 4
			cout << "you enter a small room, where you found a sword on the wall! You take it and debate on going west or south.";
			getline(cin, input);
			system("Color 2B"); //color for rooms with items
			if (input.compare("west") == 0)
				room = 3;
			if (input.compare("south") == 0)
				room = 6;
			if (input.compare("north") == 0)
				room = 5;

			inventory[1] = "sword";

			break;

		case 5: //room 5, secret room
			cout << "you've found and entered the secret room, where you encounter a monster." << endl;
			system("Color 4B"); //color for rooms with items
			Monsters();

			cout << "you can go south!" << endl;
			getline(cin, input);
			if (input.compare("south") == 0)
				room = 6;

			inventory[2] = "gold key";

			break;

		case 6: //room 6, secret room
			cout << "The human exposed the second secret room, where he exposed you to a monster encounter.";
			Monsters();
			system("Color 4B"); //color for rooms with monsters
			getline(cin, input);
			if (input.compare("west") == 0)
				room = 4;
			break;

		case 7:  //room 7
			cout << "you're in room 7, where you encounter a monster. You can go north or south";
			getline(cin, input);
			system("Color 2B"); //color for rooms with items
			if (input.compare("north") == 0)
				room = 4;
			if (input.compare("south") == 0)
				room = 8;

			inventory[3] = "red apple";

			break;

		case 8:  //room 8
			cout << "you're in room 8! you can go west or north.";
			getline(cin, input);
			system("Color 1C"); //color for plain room
			if (input.compare("west") == 0)
				room = 9;
			if (input.compare("north") == 0)
				room = 7;
			break;

		case 9:  //room 9
			cout << "you're in room 9! you can go west or east.";
			getline(cin, input);
			system("Color 1C"); //color for plain room
			if (input.compare("west") == 0)
				room = 1;
			if (input.compare("east") == 0)
				room = 10;
			break;

		case 10:  //room 10
			cout << "you're in room 10, where you see a human! you can go north or south.";
			system("Color 3C"); //color for human in room
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 9;
			if (input.compare("south") == 0)
				room = 11;

			inventory[4] = "red apple";

			break;

		case 11:  //room 11
			cout << "you're in room 11! you encounter a monster! you need a key to unlock the door.";

			system("Color 2B"); //color for rooms with items
			Monsters();

			getline(cin, input);
			if (input.compare("north") == 0)
				room = 10;
			if (input.compare("east") == 0)
				room = 12;

			inventory[5] = "silver key";

			break;

		case 12:  //room 12
			cout << "you're in room 12! you encounter a monster!";
			getline(cin, input);
			system("Color 4B"); //color for rooms with monsters
			if (input.compare("north") == 0)
				room = 1;
			if (input.compare("west") == 0)
				room = 5;
			break;

		case 13: //last room to win
			cout << "You reach the end, where you find the gold arifact! Congratulations on your journey!" << endl;
			system("Color 2B"); //color for rooms with items

			inventory[6] = "goldenartifact";

			break;
			}
		} //end switch
	} //end while loop
} //end main

void Monsters() { //monster generator

	int num = rand() % 100 + 1;
	if (num <= 50)
		cout << "A vampire appears and attacks you" << endl; //more likely
	else if (num > 51 && num <= 80)
		cout << "An alien appears and attacks you" << endl;
	else
		cout << "A zombie appears and attacks you" << endl; // less likely

}