#pragma once
#include <string>
using namespace std;

class item
{
	public:
		item(void);
		item(string n, unsigned long s, string u);
		~item(void);
		void setName(string n);
		void setAmount(int s);
		void setUnit(string u);
		string getName() const;
		unsigned long getAmount() const;
		string item::getUnit() const;
	private:
		unsigned long amount;
		string name;
		string unit;
};