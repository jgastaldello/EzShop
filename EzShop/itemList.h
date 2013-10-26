#pragma once 

#include "item.h"
#include <vector>

using namespace std;

class itemList
{
	public:
		itemList(void);
		~itemList(void);
		bool itemList::openList(string fileName);
		void addList(string name, int size);
		void removeList(string name, int size);
		void sortList();
		void saveList(string fileName);
		void viewList();
		void loadList();
	private:
		item* arrList;
		int arrIndex;
		int arrSize;
};

