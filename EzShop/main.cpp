/*
GPL v3 - October 2013
EzShop: Shopping, Simplified!
Created by: Joshua Gastaldello, [add your names here]
*/

/*
TODO:
- welcome page
- user menu
- remove items (Josh, Vikash)
- view items (Eric, Grant)
*/

#include "inventoryList.h"
#include "inventory.h"
#include <iostream>

int main()
{
	inventoryList testList = inventoryList();
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
	testList.saveInventory();
	system("pause");
	return 0;
}
