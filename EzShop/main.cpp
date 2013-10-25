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
*/

#include "inventoryList.h"
#include "inventory.h"
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

void chooseFile(inventoryList &items)
{
	string fileName;
	cout << "\nEnter your file name (no extension): ";
	getline(cin, fileName);

	while (!items.openInventory(fileName))
	{
		cout << "File does not exist!\n";
	}
}
//displays welcome and opens existing inventory
void start(inventoryList &items,bool &choice)
{
	cout << "Welcome to EzShop!\n";
	cout << "\n";
	cout << "Would you like to open an existing inventory? ";
	choice = yesOrNo();

	if (choice)
	{
		chooseFile(items);
	}
}
void menu(bool listSaved)
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
	inventoryList items = inventoryList();
	bool listSaved = false;
	start(items,listSaved);
	cout << "\n";
	menu(listSaved);
	/*
	//inventoryList testList = inventoryList();
	//inventory apple = inventory("apple", 5);
	//apple.setSize(10);
	//apple.setName("APPLE");
	testList.addInventory("apple", 5);
	testList.addInventory("orange", 7);
	testList.addInventory("peach", 1);
	testList.addInventory("computer", 3);
	testList.addInventory("ipod", 7);
	testList.addInventory("ppt file", 50);

	testList.removeInventory("ppt file", 10);
	testList.removeInventory("peach", 1);
	testList.sortInventory();
	testList.saveInventory("inventory");*/

	system("pause");
	return 0;
}