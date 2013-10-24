#pragma once
#include "inventory.h"
#include <vector>

using namespace std;

class inventoryList
{
public:
	inventoryList(void);
	~inventoryList(void);
	void addInventory(string name, int size);
	void removeInventory();
	void sortInventory();
	void saveInventory();
	void viewInventory();
	void loadInventory();
private:
	inventory* arrList;
	int arrIndex;
	int arrSize;
};

