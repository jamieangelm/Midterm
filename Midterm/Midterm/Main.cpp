//Jamie Martinez, May 15
//Game Name: The Labyrinth

#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

void Monsters(int health);

int main() { //begin main

	for (int i = 0; i < 8; i++) { //inventory begin bracket
		string inventory[8];

		inventory[0] = "Empty";
		inventory[1] = "Empty"; //key to hidden room
		inventory[2] = "Empty"; //sword to fight monsters
		inventory[3] = "Empty"; //key to win game
		inventory[4] = "Empty"; //apple for 50 health
		inventory[5] = "Empty"; //key from human
		inventory[6] = "Empty"; //apple for 150 health
		inventory[7] = "Empty"; //golden artifact to win game
	} //invetory end bracket

	int health = 200; //total health

	string input = "a";
	int room = 1; //start at the first room
	string inventory[8];  //7 items listed above

	cout << "You feel the eerie atmosphere as you approach 'The Labyrinth'..." << endl; //introduction to the game
	cout << "----------------------------------------------------------------" << endl; //make it spaced nicely
	cout << "You read the note with your mission on it from King Levy." << endl;
	PlaySound("levy.wav", NULL, SND_FILENAME);
	cout << "You tell yourself that you're going to complete the mission." << endl;
	PlaySound("sochoeun.wav", NULL, SND_FILENAME);

	while (input.compare("quit") != 0) { //begin while loop
		switch (room) { //begin switch
		case 1:  //room 1
			system("Color 1C"); //color for plain room

			cout << "You enter a room that's barely lit with a few torches. there's a spine chilling feeling." << endl;
			cout << "You can go north or south." << endl;
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 2;
			else if (input.compare("south") == 0)
				room = 10;
			else
				cout << "invalid input" << endl;
			break;

		case 2:  //room 2
			cout << "You enter a more lit room with a table in the middle of the room." << endl;
			if (inventory[1] != ("silver key")) { //no silver key in inventory
				cout << "there's a silver key on the table." << endl;
			} //say there's a key on the table
			getline(cin, input);
			if (input.compare("silver key") == 0) { //silver key is now in the inventory

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
			cout << "you're in a room that has a lot of old, fragile, vases... nothing too interesting." << endl;
			cout << "You can go east or west." << endl;
			getline(cin, input);
			system("Color 1C"); //color for plain room
			if (input.compare("east") == 0)
				room = 4;
			if (input.compare("west") == 0)
				room = 2;
			break;

		case 4: //room 4
			cout << "you enter a very small room." << endl;
			if (inventory[2] != ("sword")) { //no sword in inventory
				cout << "You see a sword on one of the walls." << endl;
			}
			getline(cin, input);
			if (input.compare("sword") == 0) { //sword is now in the inventory

				cout << "You grabbed the sword!" << endl;
			}
			cout << "you decide if you want to go south or west." << endl;
			system("Color 2B"); //color for rooms with items
			getline(cin, input);
			if (input.compare("west") == 0)
				room = 3;
			if (input.compare("south") == 0)
				room = 7;
			if (input.compare("north") == 0) {
				if (inventory[1].compare("silver key") == 0) { //have to have key to enter the room
					cout << "You unlocked the door." << endl; //if you have the key, you can enter the room
					room = 5;
				}
				else
					cout << "Door is locked." << endl; // door is locked
			}
			if (input.compare("east") == 0) {
				if (inventory[1].compare("bronze key") == 0) { //have to have key to enter the room
					cout << "You unlocked the door." << endl; //if you have the key, you can enter the room
					room = 6;
				}
				else
					cout << "Door is locked." << endl; // door is locked
			}

			inventory[2] = "sword";

			break;

		case 5: //room 5, secret room
			cout << "you've found and entered the secret room." << endl;

			if (inventory[3] != ("gold key")) { //no gold key in inventory
				cout << "there's a gold key on the table" << endl;
			} //say there's a key on the table
			getline(cin, input);
			if (input.compare("gold key") == 0) { //gold key is now in the inventory

				cout << "You grabbed the key!" << endl;
			}
			cout << "you can go south!" << endl;
			getline(cin, input);
			if (input.compare("south") == 0) {
				if (inventory[3] == "gold key")
					room = 14;
				else
					room = 4;
			}

			else
				cout << "invalid input" << endl;

			inventory[3] = "gold key";

			break;

		case 6: //room 6, secret room
			cout << "The human exposed you to this secret room, where he exposed you to a monster encounter.";
			system("Color 4B"); //color for rooms with monsters
			Monsters(health);

			cout << "you can only go west." << endl;
			getline(cin, input);
			if (input.compare("west") == 0)
				room = 4;
			break;

		case 7:  //room 7
			cout << "you enter a dark room, and you hear a low grunting." << endl;

			system("Color 2B"); //color for rooms with items
			Monsters(health);
			if (inventory[4] != ("red apple")) { //no red apple in inventory
				cout << "you kill the monster with your sword, he drops a red apple" << endl;
			} //say there's an apple
			getline(cin, input);
			if (input.compare("red apple") == 0) { //red apple is now in the inventory
			
				cout << "You grabbed the red apple!" << endl;
			}
			cout << "You can go north or south" << endl;
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 4;
			if (input.compare("south") == 0)
				room = 8;

			inventory[4] = "red apple";

			break;

		case 8:  //room 8
			cout << "you enter a room that's basically empty." << endl;
			cout << "you can go west or north." << endl;
			getline(cin, input);
			system("Color 1C"); //color for plain room
			if (input.compare("west") == 0)
				room = 9;
			if (input.compare("north") == 0)
				room = 7;
			break;

		case 9:  //room 9
			cout << "you enter another empty room." << endl;
			cout << "you can go west or east." << endl;
			getline(cin, input);
			system("Color 1C"); //color for plain room
			if (input.compare("west") == 0)
				room = 10;
			if (input.compare("east") == 0)
				room = 8;
			break;

		case 10:  //room 10, encounter a human
			cout << "you enter a room where you see a human standing and facing the corner!" << endl;
			system("Color 5D"); //color for human in room

			if (inventory[5] != ("bronze key")) { //no bronze key in inventory
				cout << "he gives you a bronze key" << endl;
			} //say there's a bronze key
			getline(cin, input);
			if (input.compare("bronze key") == 0) { //bronze key is now in the inventory
		
				cout << "You grabbed the bronze key!" << endl;
			}
			cout << "you can go north or south." << endl;
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 1;
			if (input.compare("south") == 0)
				room = 11;

			inventory[5] = "bronze key";

			break;

		case 11:  //room 11
			cout << "There's a table in the middle of the room" << endl;
			system("Color 2B"); //color for rooms with items

			if (inventory[6] != ("golden apple")) { //no golden apple in inventory
				cout << "a golden apple is on the table" << endl;
			} //say there's a golden apple
			getline(cin, input);
			if (input.compare("golden apple") == 0) { //golden apple is now in the inventory
		
				cout << "You grabbed the golden apple!" << endl;
			}
			cout << "you can go north or south" << endl << endl;
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 10;
			if (input.compare("south") == 0)
				room = 12;

			inventory[6] = "golden apple";

			break;

		case 12:  //room 12
			cout << "you enter a dark room. You hear footsteps." << endl;
			Monsters(health);

			system("Color 4B"); //color for rooms with items
			cout << "You can go north or east." << endl;
			getline(cin, input);
			if (input.compare("north") == 0)
				room = 11;
			if (input.compare("east") == 0) {
				if (inventory[1].compare("gold key") == 0) { //have to have key to enter the room
					cout << "You unlocked the door." << endl; //if you have the key, you can enter the room
					room = 13;
				}
				else
					cout << "Door is locked." << endl; // door is locked
			}

			break;

		case 13: //last room to win
			cout << "You reach the end, where you find the gold arifact! Congratulations on your journey!" << endl;
			system("Color 2B"); //color for rooms with items

			if (inventory[7] != ("golden artifact")) { //no golden artifact in inventory
				cout << "You see the golden artifact" << endl;
			} //say there's a golden artifact
			getline(cin, input);
			if (input.compare("golden artifact") == 0) { //golden artifact is now in the inventory
				
				cout << "You grabbed the golden artifact!" << endl;
			}

			inventory[7] = "golden artifact";

			break;

		case 14: // after you grab the silver key, this is the room without it
			cout << "you re-enter the lit room." << endl;
			cout << "you can go east or south." << endl;
			break;

		case 15: // after you grab the sword, this is the room without the sword
			cout << "you're back in the very small room, after unlocking the secret room." << endl;
			cout << "you can go west or south." << endl;
			break;

		case 16: // after you grab the gold key, this is the room without it
			cout << "you're back in the secret room, which isn't a secret anymore." << endl;
			cout << "you can go south." << endl;
			break;

		case 17: // after you grab the red apple, this is the room without it
			cout << "you see the monster corpse on the floor from earlier." << endl;
			cout << "you can go north or south." << endl;
			break;

		case 18: // the human isn't in this room anymore
			cout << "you walk back into the room where you met the human, but he went somewhere else." << endl;
			cout << "you can go north, east, or south." << endl;
			break;

		case 19: // after you grab the gold apple, this is the room without it
			cout << "you enter a room that's empty." << endl;
			cout << "you can go north or south." << endl;
			break;

		} //end switch
	} //end while loop
} //end main

void Monsters(int health) { //monster generator begin

	int num = rand() % 100 + 1;
	if (num <= 50) { //if begin
		cout << "A vampire appears and attacks you" << endl; //more likely
		health = health - 100;
		cout << "Your health is now " << health << "." << endl;
	} //if end

	else if (num > 51 && num <= 80) { //else if begin
		cout << "An alien appears and attacks you" << endl;
		health = health - 50;
		cout << "Your health is now " << health << "." << endl;
	} //else if end

	else { //else begin
		cout << "A zombie appears and attacks you" << endl; // less likely
		health = health - 20;
		cout << "Your health is now " << health << "." << endl;
	} //else end

} //monster generator end