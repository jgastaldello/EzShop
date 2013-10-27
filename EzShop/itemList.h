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
		void addListItem(string name, int size, string unit);
		void removeListItem(string name, int size);
		void sortList();
		void saveList(string fileName);
		void viewList() const;
		void loadList();
	private:
		vector<item> list;
};