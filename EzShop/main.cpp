/*
GPL v3 - October 2013
EzShop: Shopping, Simplified!
Created by: Joshua Gastaldello, [add your names here]
*/

/*
TODO:
- user menu
- remove items (Josh, Vikash)
- load items from file (Erick, Grant)
- change itemList to itemList
- change inventory to list
*/

//DO NOT CLEAR THE SCREEN UNTIL THE PROGRAM IS COMPLETE!

#include "itemList.h"
#include "item.h"
#include <iostream>

//gets a Y or N input and returns T or F
bool yesOrNo()
{
	string input;
	cout << "(Y or N) ";
	cin >> input;
	while ((input != "Y") && (input != "y") && (input != "N") && (input != "n"))
	{
		cout << "Invalid input. Try again: ";
		cin >> input;
	}
	cin.sync();
	return ((input == "Y") || (input == "y"));
}
//asks user for number between the specified range
int numberRangeChoice(int min, int max)
{
	int input;
	cout << "("<<min<<" to "<<max<<") ";
	cin >> input;
	while (input < min || input > max)
	{
		cout << "Invalid input. Try again: ";
		cin >> input;
	}
	cin.sync();
	return input;
}

void chooseFile(itemList &inventoryList)
{
	string fileName;
	cout << "\nEnter your file name (no extension): ";
	getline(cin, fileName);

	while (!inventoryList.openList(fileName))
	{
		cout << "File does not exist!\n";
	}
}
//displays welcome and opens existing inventory
void start(itemList &inventoryList, bool &choice)
{
	cout << "Welcome to EzShop!\n";
	cout << "\n";
	cout << "Would you like to open an existing inventory? ";
	choice = yesOrNo();

	if (choice)
	{
		chooseFile(inventoryList);
	}
}
void viewInventory(itemList &inventoryList)
{
	cout << "";
}
void menu(bool listSaved, itemList &inventoryList)
{
	int totalMenuItems = 0;
	cout << ++totalMenuItems << ": Add items\n";
	cout << ++totalMenuItems << ": Remove items\n";
	cout << ++totalMenuItems << ": View items\n";
	cout << ++totalMenuItems << ": Save\n";
	cout << ++totalMenuItems << ": Save as...\n";
	cout << ++totalMenuItems << ": Open file...\n";
	cout << ++totalMenuItems << ": Quit\n";

	cout << "\nChoose a task: ";
	int task = numberRangeChoice(1, totalMenuItems);

	switch (task)
	{
	case 1:
		//add items 
		break;
	case 2:
		//remove items
		break;
	case 3:
		//view items
		cout << "\n";
		inventoryList.viewList();
		break;
	case 4:
		//save list
		break;
	case 5:
		//save list as...
		break;
	case 6:
		//open file as...
		break;
	default:
		break;
	}
}
int main()
{
	itemList inventoryList = itemList();
	bool listSaved = false;
	start(inventoryList,listSaved);
	cout << "\n";
	
	//itemList testList = itemList();
	//inventory apple = inventory("apple", 5);
	//apple.setSize(10);
	//apple.setName("APPLE");

	inventoryList.addList("apple", 5);
	inventoryList.addList("orange", 7);
	inventoryList.addList("peach", 1);
	inventoryList.addList("computer", 3);
	inventoryList.addList("ipod", 7);
	inventoryList.addList("ppt file", 50);

	inventoryList.removeList("ppt file", 10);
	inventoryList.removeList("peach", 1);
	inventoryList.sortList();

	menu(listSaved, inventoryList);

	system("pause");
	return 0;
}