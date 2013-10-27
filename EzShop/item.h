#pragma once
#include <string>
using namespace std;

class item
{
	public:
		item(void);
		item(string n, int s, string u);
		~item(void);
		void setName(string n);
		void setSize(int s);
		void setUnit(string u);
		string getName() const;
		int getSize() const;
		string item::getUnit() const;
	private:
		int size;
		string name;
		string unit;
};