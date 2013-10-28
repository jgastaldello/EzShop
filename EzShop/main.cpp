/*
GPL v3 - October 2013
EzShop: Shopping, Simplified!
Created by: Joshua Gastaldello, [add your names here]
*/

/*
TO-DO:
- user menu
	- inventory
		- add item
		- remove item
		- save inventory
		- save inventory as...
		- open inventory...
	- recipe
		- add recipe [will save the recipe to its own file at the end of function]
		- use recipe
		- remove recipe
		- save all recipe's
		- open inventory...
	- main
		- open existing inventory
		- open existing recipe(s)
		- view inventory list
		- view a recipe [function to choose one]
		- manage inventory {goes to inventory menu}
		- manage recipies {goes to recipe menu}
- load items from file [itemList.cpp] (Erick, Grant)
- recipe.h and .cpp
*/

//DO NOT INSERT ANY CLEAR SCREENS UNTIL THE PROGRAMMING IS COMPLETE!
//always call sortList() before you viewList() or saveList()!
//update the todo list!!!!!!

#include "itemList.h"
#include "item.h"
#include <iostream>
#include <limits.h>

bool yesOrNo();
int numberRangeChoice(int min, int max);
void chooseFile(itemList &list);
void start(itemList &inventoryList, bool &choice);
void displayInventory(itemList &inventoryList);
void mainMenu(bool listSaved, itemList &inventoryList);

int main()
{
	
	itemList inventoryList;
	bool listSaved = false;
	start(inventoryList,listSaved);
	cout << "\n";

/*
	inventoryList.addListItem("apple", 5,"items");
	inventoryList.addListItem("orange", 7, "items");
	inventoryList.addListItem("peach", 1, "items");
	inventoryList.addListItem("computer", 3, "items");
	inventoryList.addListItem("ipod", 7, "items");
	inventoryList.addListItem("ppt file", 50, "files");
	inventoryList.addListItem("laptop", 3, "items");
	inventoryList.addListItem("phone", 100, "items");
	inventoryList.addListItem("milk", 2, "2L jugs");
	inventoryList.addListItem("coke", 12, "1");
	inventoryList.addListItem("storage", 1024, "bytes");
	inventoryList.addListItem("keyboards", 3, "items");

	inventoryList.removeListItem("ppt file", 10);
	inventoryList.removeListItem("peach", 1);
	inventoryList.sortList();
	inventoryList.saveList("inventory");
*/
	mainMenu(listSaved, inventoryList);


	system("pause");
	return 0;
}

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
//opens an inventory file
void chooseFile(itemList &list)
{
	string fileName;
	cout << "\nEnter your file name (no extension): ";
	getline(cin, fileName);

	while (!list.openList(fileName))
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
//prints the inventory list
void displayInventory(itemList &inventoryList)
{
	cout << "\nHere is your current inventory:\n\n";
	inventoryList.viewList();
	cout << "\n";
}
void mainMenu(bool listSaved, itemList &inventoryList)
{
		/*-main
		- open existing inventory
		- open existing recipe(s)
		- view inventory list
		- view a recipe[function to choose one]
		- manage inventory{ goes to inventory menu }
		-manage recipies{ goes to recipe menu }*/
	/*
	Arthur -main
		- manage inventory {goes to inventory menu}
		- manage recipies {goes to recipe menu}
		- manage shopping list {goes to recipe menu}
	*/

	int totalMenuItems = 0;// user option
	/*
	cout << ++totalMenuItems << ": Add items\n";
	cout << ++totalMenuItems << ": Remove items\n";
	cout << ++totalMenuItems << ": View items\n";
	cout << ++totalMenuItems << ": Save\n";
	cout << ++totalMenuItems << ": Save as...\n";
	cout << ++totalMenuItems << ": Open file...\n";
	cout << ++totalMenuItems << ": Quit\n";
	*/
	cout << ++totalMenuItems << ": manage inventory\n";
	cout << ++totalMenuItems << ": manage recipes\n";
	cout << ++totalMenuItems << ": manage shopping list\n";
	cout << ++totalMenuItems << ": Quit"<<endl;

	cout << "\nChoose a task: ";
	int task = numberRangeChoice(1, totalMenuItems);

	switch (task)
	{
	case 1:
		//manage inventory
		inventoryManage();
		break;
	case 2:
		//manage recipes
		break;
	case 3:
		//manage shopping list
		
		break;
	case 4:
		//Quit
		
		break;
	default:
		cout <<"Error: MENU default case\n";
		break;
	}
}
