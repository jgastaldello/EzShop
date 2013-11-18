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
		void addListItem(string name, unsigned long amount, string unit);
		void removeListItem(string name, unsigned long amountToRemove);
		void sortList();
		void saveList(string fileName);
		void viewList() const;
		void loadList();
		int searchList(string target) const;
	private:
		vector<item> list;
};
