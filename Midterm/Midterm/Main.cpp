//Jamie Martinez, April 12
//Game Name: The Labyrinth

#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

int health = 500; //total health

void Monsters();

int main() { //begin main

	for (int i = 0; i < 8; i++) {
		string inventory[8];

			inventory[0] = "Empty";
		inventory[1] = "Empty"; //adds ~ 50 health
		inventory[2] = "Empty"; //key needed to finish game
		inventory[3] = "Empty";  //adds ~ 350 health
		inventory[4] = "Empty";  //fight monsters
		inventory[5] = "Empty";  //to other hidden room from human
		inventory[6] = "Empty";  //key to hidden room
		inventory[7] = "Empty";  //wins game
	}

	string input = "a";
	int room = 1;
	string inventory[8];  //7 items listed above

	cout << "You feel the eerie atmosphere as you approach 'The Labyrinth'..." << endl; //introduction to the game
	cout << "----------------------------------------------------------------" << endl; //make it spaced nicely
	
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
			if (inventory[1] == ("silver key")); //no silver key in inventory
				cout << "there's a silver key on the table" << endl; //say there's a key on the table
			getline(cin, input);
			if (input.compare("silver key") == 0) { //silver key is now in the inventory
				inventory[1] = "silver key"; //put in 
				cout << "You grabbed the key!" << endl;
			}
				system("Color 2B"); //color for rooms with items

				cout << "You decide if you want to go east or south." << endl;
				getline(cin, input);
				if (input.compare("east") == 0)
					room = 3;
				else if (input.compare("south") == 0)
					room = 1;
				else
					cout << "invalid input" << endl;

				inventory[1] = "silver key";

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
			cout << "you enter a very small room." << endl;
			if (inventory[2] == ("sword")); //no sword in inventory
				cout << "You see a sword on one of the walls.";
			getline(cin, input);
			if (input.compare("sword") == 0) { //sword is now in the inventory
				inventory[2] = "sword"; //put in 
				cout << "You grabbed the sword!" << endl;
			}
			system("Color 2B"); //color for rooms with items
			getline(cin, input);
			if (input.compare("west") == 0)
				room = 3;
			if (input.compare("south") == 0)
				room = 6;
			if (input.compare("north") == 0)
				room = 5;
			else
				cout << "invalid input" << endl;

			inventory[2] = "sword";

			break;

		case 5: //room 5, secret room
			cout << "you've found and entered the secret room." << endl;

			if (inventory[3] == ("gold key")); //no gold key in inventory
				cout << "there's a gold key on the table" << endl; //say there's a key on the table
			getline(cin, input);
			if (input.compare("gold key") == 0) { //gold key is now in the inventory
				inventory[3] = "gold key"; //put in 
				cout << "You grabbed the key!" << endl;
			}
			cout << "you can go south!" << endl;
			getline(cin, input);
			if (input.compare("south") == 0)
				room = 4;
			else
				cout << "invalid input" << endl;

			inventory[3] = "gold key";

			break;

		case 6: //room 6, secret room
			cout << "The human exposed you to this secret room, where he exposed you to a monster encounter.";
			system("Color 4B"); //color for rooms with monsters
			Monsters();
			
			getline(cin, input);
			if (input.compare("west") == 0)
				room = 4;
			break;

		case 7:  //room 7
			cout << "you enter a dark room, and you hear a low grunting.";

			system("Color 2B"); //color for rooms with items
			Monsters();
			if (inventory[4] == ("red apple")); //no red apple in inventory
				cout << "you kill the monster, he drops a red apple" << endl; //say there's an apple
			getline(cin, input);
			if (input.compare("red apple") == 0) { //red apple is now in the inventory
				inventory[4] = "red apple"; //put in 
				cout << "You grabbed the red apple!" << endl;
			}
			cout << "You can go north or south" << endl;
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 4;
			if (input.compare("south") == 0)
				room = 8;

			inventory[4] = "silver key";

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

		case 10:  //room 10, encounter a human
			cout << "you're in room 10, where you see a human!";
			system("Color 3C"); //color for human in room

			if (inventory[5] == ("bronze key")); //no bronze key in inventory
				cout << "he gives you a bronze key" << endl; //say there's a bronze key
			getline(cin, input);
			if (input.compare("bronze key") == 0) { //bronze key is now in the inventory
				inventory[5] = "bronze key"; //put in 
				cout << "You grabbed the bronze key!" << endl;
			}
			cout << "you can go north or south." << endl;
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 9;
			if (input.compare("south") == 0)
				room = 11;

			inventory[5] = "bronze key";

			break;

		case 11:  //room 11
			cout << "There's a table in the middle of the room";
			system("Color 2B"); //color for rooms with items

			if (inventory[6] == ("golden apple"); //no golden apple in inventory
				cout << "a golden apple is on the table" << endl; //say there's a golden apple
			getline(cin, input);
			if (input.compare("golden apple") == 0) { //golden apple is now in the inventory
				inventory[6] = "golden apple"; //put in 
				cout << "You grabbed the golden apple!" << endl;
			}
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 10;
			if (input.compare("east") == 0)
				room = 12;

			inventory[6] = "golden apple";

			break;

		case 12:  //room 12
			cout << "you enter a dark room. You hear footsteps." << endl;
			Monsters();

			system("Color 4B"); //color for rooms with items
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 1;
			if (input.compare("west") == 0)
				room = 5;


			break;

		case 13: //last room to win
			cout << "You reach the end, where you find the gold arifact! Congratulations on your journey!" << endl;
			system("Color 2B"); //color for rooms with items

			if (inventory[7] == ("golden artifact")); //no golden artifact in inventory
				cout << "you see the golden artifact" << endl; //say there's a golden artifact
			getline(cin, input);
			if (input.compare("golden artifact") == 0) { //golden artifact is now in the inventory
				inventory[7] = "golden artifact"; //put in 
				cout << "You grabbed the golden artifact!" << endl;
			}

			inventory[7] = "goldenartifact";

			break;
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