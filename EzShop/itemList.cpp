#include "itemList.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

//constructor
itemList::itemList(void)
{
	arrList = new item[10];
	arrIndex = 0;// indicate the last element
	arrSize = 10;// the size of the array
}
//destructor
itemList::~itemList(void)
{
	delete[] arrList;
}
//opens an existing file into the array
bool itemList::openList(string fileName)//Erick and Grant
{

	return true; //return true if the file exists, false if it doesn't
}
//adds an item to the end of the item list
void itemList::addList(string name, int size)
{
	//need to check if the size reaches the limit or not
	arrList[arrIndex] = item(name, size);
	arrIndex++;
}
//removes an item from the List
void itemList::removeList(string itemName, int numToRemove) //Josh and Vikash
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
//Sorts the List array using insertion sort
void itemList::sortList() //Arthur and Karen
{
	for (int i = 0; i < arrIndex; i++) 
	{
		string key = arrList[i].getName();
		for (int j = i - 1; j >= 0 && (arrList[j].getName()).compare(key) > 0; j--) 
		{
			item temp = arrList[j + 1];
			arrList[j + 1] = arrList[j];
			arrList[j] = temp;
		}
	}
}
//saves the inventory to a txt file
void itemList::saveList(string fileName)
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
	viewList();
}
//outputs the array into a readable format
void itemList::viewList()
{
	//need to add legnths for amount and units
	string itemHeader = "Item name", separator = " | ", amountHeader = "Amount", unitHeader = "Units";
	int longestItemName = itemHeader.length(), totalLength = itemHeader.length() + (2 *separator.length()) + amountHeader.length() + unitHeader.length();
	for (int x = 0; x < arrIndex; x++)
	{
		string name = arrList[x].getName();
		int length = name.length();

		if (length > longestItemName)
		{
			longestItemName = length;
		}
	}
	cout << setw(longestItemName) << itemHeader << separator << amountHeader << separator << unitHeader << "\n";
	for (int x = 1; x <= totalLength; x++)
	{
		cout << "-";
	}
	cout << "\n";
	for (int x = 0; x < arrIndex; x++)
	{
		cout << setw(longestItemName) << arrList[x].getName() << separator << arrList[x].getSize() << "\n";
	}
}