#include "inventoryList.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

inventoryList::inventoryList(void)
{
	arrList = new inventory[10];
	arrIndex = 0;// indicate the last element
	arrSize = 10;// the size of the array
}
inventoryList::~inventoryList(void)
{
	delete[] arrList;
}
//opens an existing file into the array
bool inventoryList::openInventory(string fileName)//Erick and Grant
{

	return true; //return true if the file exists, false if it doesn't
}
void inventoryList::addInventory(string name, int size)
{
	//need to check if the size reaches the limit or not
	arrList[arrIndex] = inventory(name, size);
	arrIndex++;
}
//removes an item from the inventory
void inventoryList::removeInventory(string itemName, int numToRemove) //Josh and Vikash
{
	//std::find(arrList[1].getName(), arrList[arrIndex].getName(), name); //idk how to use this...
	int location = 1;
	//searches for the specified item
	for (int x = 0; x < arrIndex; x++)
	{
		if (itemName == arrList[x].getName())
		{
			location = x;
			break;
		}
	}
	arrList[location].setSize(arrList[location].getSize() - numToRemove);

	if (arrList[location].getSize() == 0)
	{
		//arrList[location].erase(); //this doesn't work?
	}
}
//Sorts the inventory array using insertion sort
void inventoryList::sortInventory() //Arthur and Karen
{
	for (int i = 0; i < arrIndex; i++) 
	{
		string key = arrList[i].getName();
		for (int j = i - 1; j >= 0 && (arrList[j].getName()).compare(key) > 0; j--) 
		{
			inventory temp = arrList[j + 1];
			arrList[j + 1] = arrList[j];
			arrList[j] = temp;
		}
	}
}
//saves the inventory to a txt file
void inventoryList::saveInventory(string fileName) 
{
	ofstream myFile;
	fileName.append(".csv");
	cout << "The full filename is " << fileName << "\n";
	myFile.open(fileName);

	for (int i = 0; i < arrIndex; i++)
	{
		myFile << arrList[i].getName() << " , " << arrList[i].getSize() << "\n";
	}
	myFile.close();
	cout << "Inventory List has been saved. :D" << endl;
	viewInventory();
}
//outputs the array into a readable format
void inventoryList::viewInventory()
{
	int longestItemName = 0;
	for (int x = 0; x < arrIndex; x++)
	{
		string name = arrList[x].getName();
		int length = name.length();

		if (length > longestItemName)
		{
			longestItemName = length;
		}
	}
	for (int x = 0; x < arrIndex; x++)
	{
		cout << setw(longestItemName)  << arrList[x].getName() << " | " << arrList[x].getSize() << "\n";
	}
}