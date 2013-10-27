#include "itemList.h"

#include <fstream>
#include <iostream>
#include <iomanip> //cout setw()
#include <algorithm> //std::find

//constructor
itemList::itemList(void)
{
	vector<item> list;
	//list.reserve(10);
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
void itemList::addListItem(string name, unsigned long amount, string unit)
{
	//need to check if the item exists already
	list.end();
	list.push_back(item(name, amount, unit));
 	//arrList[arrIndex] = item(name, size);
	//arrIndex++;
}
//removes an item from the List
void itemList::removeListItem(string itemName, unsigned long amountToRemove) //Josh and Vikash
{
	int location = 0;
	//searches for the specified item
	for (unsigned int x = 0; x <= list.size(); x++)
	{
		if (itemName == list[x].getName())
		{
			location = x;
			break;
		}
	}
	
	list[location].setAmount(list[location].getAmount() - amountToRemove);
	//arrList[location].setSize(arrList[location].getSize() - numToRemove);

	if (list[location].getAmount() == 0)
	{
		list.erase(list.begin() + location);
		//delete &arrList[location];
	}
}
//Sorts the List array using insertion sort
void itemList::sortList() //Arthur and Karen
{
	for (unsigned int i = 0; i < list.size(); i++)
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
		myFile << list[i].getName() << " , " << list[i].getAmount() << " , " << list[i].getUnit()<< "\n";
	}
	myFile.close();
}
//outputs the array into a readable format
void itemList::viewList() const
{
	//header
	string itemHeader = "Item name", separator = " | ", amountHeader = "Amount", unitHeader = "Units";
	//sets the size as the header itself
	int longestItemName = itemHeader.length(), longestAmountName = amountHeader.length(), longestUnitName = unitHeader.length();
	//total header legnth 
	int totalLength = 2 * separator.length();

	for (unsigned int i = 1; i <= 3; i++)
	{
		for (unsigned int x = 0; x < list.size(); x++)
		{
			string header;
			int stringLength;
			if (i == 1)
			{
				header = list[x].getName();
				stringLength = header.length();

				if (stringLength > longestItemName)
				{
					longestItemName = stringLength;
				}
			}
			else if (i == 2)
			{
				header = to_string(list[x].getAmount()); //to_stirng converts number to string
				stringLength = header.length();

				if (stringLength > longestAmountName)
				{
					longestAmountName = stringLength;
				}
			}
			else if (i == 3)
			{
				header = list[x].getUnit();
				stringLength = header.length();

				if (stringLength > longestUnitName)
				{
					longestUnitName = stringLength;
				}
			}
			
		}
	}
	//prints headers
	cout << left;
	cout << setw(longestItemName) << itemHeader << separator;
	cout << setw(longestAmountName) << amountHeader << separator;
	cout << setw(longestUnitName) << unitHeader << "\n";
	totalLength += longestItemName + longestAmountName + longestUnitName;
	for (unsigned int x = 1; x <= totalLength; x++)
	{
		cout << "-";
	}
	cout << "\n";
	//prints all the items in the list
	for (unsigned int x = 0; x < list.size(); x++)
	{
		cout << left << setw(longestItemName) << list[x].getName() << separator;
		cout << right << setw(longestAmountName) << list[x].getAmount() << separator;
		cout << left << setw(longestUnitName) << list[x].getUnit() << "\n";
	}
	for (unsigned int x = 1; x <= totalLength; x++)
	{
		cout << "-";
	}
	cout << "\n";
}