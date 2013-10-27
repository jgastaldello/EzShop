#include "itemList.h"

#include <fstream>
#include <iostream>
#include <iomanip> //cout setw()
#include <algorithm> //std::find

//constructor
itemList::itemList(void)
{
	vector<item> list;
	list.reserve(10);
	//item arrList = new item[10];
	//arrIndex = 0;// indicate the last element
	//arrSize = 10;// the size of the array
}
//destructor
itemList::~itemList(void)
{
	//delete[] arrList;
}
//opens an existing file into the array
bool itemList::openList(string fileName)//Erick and Grant
{
	return true; //return true if the file exists, false if it doesn't
}
//adds an item to the end of the item list
void itemList::addListItem(string name, int size, string unit)
{
	//need to check if the size reaches the limit or not
	list.end();
	list.push_back(item(name, size, unit));
 	//arrList[arrIndex] = item(name, size);
	//arrIndex++;
}
//removes an item from the List
void itemList::removeListItem(string itemName, int numToRemove) //Josh and Vikash
{
	int location = 0;
	//searches for the specified item
	for (unsigned int x = 0; x <= list.size(); x++)
	{
		if (itemName == list[location].getName())
		{
			location = x;
			break;
		}
	}
	
	list[location].setSize(list[location].getSize() - numToRemove);
	//arrList[location].setSize(arrList[location].getSize() - numToRemove);

	if (list[location].getSize() == 0)
	{
		list.erase(list.begin() + location);
		//delete &arrList[location];
	}
}
//Sorts the List array using insertion sort
void itemList::sortList() //Arthur and Karen
{
	for (int i = 0; i < list.size(); i++) 
	{
		string key = list[i].getName();
		//string key = arrList[i].getName();
		//for (int j = i - 1; j >= 0 && (arrList[j].getName()).compare(key) > 0; j--) 
		for (int j = i-1; j >= 0 && (list[j].getName()).compare(key) > 0; j--)
		{
			item temp = list[j + 1];
			list[j + 1] = list[j];
			list[j] = temp;
			/*item temp = arrList[j + 1];
			arrList[j + 1] = arrList[j];
			arrList[j] = temp;*/
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

	for (unsigned int i = 0; i < list.size(); i++)
	{
		myFile << list[i].getName() << " , " << list[i].getSize() << "\n";
	}
	myFile.close();
	cout << "Inventory List has been saved. :D" << endl;
	viewList();
}
//outputs the array into a readable format
void itemList::viewList() const
{
	//need to add legnths for amount and units
	string itemHeader = "Item name", separator = " | ", amountHeader = "Amount", unitHeader = "Units";
	int longestItemName = itemHeader.length(), totalLength = itemHeader.length() + (2 *separator.length()) + amountHeader.length() + unitHeader.length();
	for (int x = 0; x < list.size(); x++)
	{
		string name = list[x].getName();
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
	for (int x = 0; x < list.size(); x++)
	{
		cout << setw(longestItemName) << list[x].getName() << separator << list[x].getSize() << "\n";
	}
}