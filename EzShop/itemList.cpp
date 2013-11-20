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
	ifstream ist(fileName.c_str()); // open file
	// Check if file opened correctly
	if (ist.fail())
	{
		cout << "File not found\n";
		return false;
	}
	cout << "File is here :D\n";
	string itemName, itemUnit, comma;
	int itemSize;

	while (ist >> itemName >> comma >> itemSize >> comma >> itemUnit)
	{

		//cout<< itemName<<comma<<itemSize<<comma<<itemUnit<<"\n";
		addListItem(itemName, itemSize, itemUnit);
	}

	return true; //return true if the file exists, false if it doesn't
}
//adds an item to the end of the item list
void itemList::addListItem(string name, unsigned long amount, string unit)
{
	//need to check if the item exists already
	int location = searchList(name);
	if (location == -1)
	{
		if (unit != "g" || unit != "kg" || unit != "mL" || unit != "L" )
		{
			cout<< "Sorry: This item will be not added \n TYPE: The unit "<< unit << "is not supported in this program. Please convert your unit in terms of g, kg, mL, or L.\n ";
			return;
		}
		list.end();
		list.push_back(item(name, amount, unit));
	}else{
		if(list[location].getUnit() == unit){
			int tmpSize = list[location].getAmount();
			tmpSize += amount;
			list[location].setAmount(tmpSize);
		}else{
			//need to change the unit
			int tmpSize = list[location].getAmount();
			if (unit == "kg" && list[location].getUnit() == "g")
			{
				tmpSize += amount * 1000;
				
			}else if (unit == "L" && list[location].getUnit() == "mL")
			{
				tmpSize += amount * 1000;				
			}else if (unit == "g" && list[location].getUnit() == "kg")
			{
				tmpSize *= 1000;
				tmpSize += amount;				
				list[location].setUnit(unit);				

			}else if (unit == "mL" && list[location].getUnit() == "L")
			{
				tmpSize *= 1000;
				tmpSize += amount;			
				list[location].setUnit(unit);
			}else{
				cout<< "Sorry: This item will be not added \n TYPE: The unit "<< unit << "and/or "<< list[location].getUnit() <<"is/are not supported in this program. Please convert your unit in terms of g, kg, mL, or L.\n ";
				return;
			}
			list[location].setAmount(tmpSize);
			
		}
		
	}
 
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
	//There are nothing to view if it is empty
	if (isEmpty())
	{
		cout<<"SORRY: The List is empty. \n";
		return;
	}
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

int itemList::searchList(string target) const
{
	for (int i = 0; i < list.size() ; i++)
	{
		string item = list[i].getName();
		if (item == target)
		{
			return i;
		}
	}
	return -1;
}
bool itemList::isEmpty(void) const
{
	return (list.size()==0);
}



