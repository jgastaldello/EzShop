#include "inventoryList.h"
#include <fstream>
#include <iostream>

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
void inventoryList::addInventory(string name, int size)
{
	//need to check if the size reaches the limit or not
	arrList[arrIndex] = inventory(name, size);
	arrIndex++;
}
void inventoryList::removeInventory()
{
}
void inventoryList::sortInventory() //insertion sort
{
	for (int i = 1; i < arrIndex; i++) {
		string key = arrList[i].getName();
		for (int j = i - 1; j >= 0 && (arrList[j].getName()).compare(key) > 0; j--) {
			inventory temp = arrList[j + 1];
			arrList[j + 1] = arrList[j];
			arrList[j] = temp;
		}
	}
}
void inventoryList::saveInventory()
{
	ofstream myFile;
	string fileName = "Inventory.txt";
	myFile.open(fileName);
	//myFile <<"Inventory \n";
	//myFile <<"Inventory Name , Inventory amount \n";
	for (int i = 0; i< arrIndex; i++)
	{
		myFile << arrList[i].getName() << " , " << arrList[i].getSize() << "\n";
	}
	myFile.close();
	cout << "Inventory List has been saved. :D" << endl;
	viewInventory();
}
void inventoryList::viewInventory()
{
}