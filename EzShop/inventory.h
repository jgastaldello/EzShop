#pragma once
#include <string>
using namespace std;
class inventory
{
public:
	inventory(void);
	inventory(string n , int s);
	~inventory(void);
	void setName(string n);
	void setSize(int s);
	void setUnit(string u);
	string getUnit() const;
	string getName() const;
	int getSize() const;
private:
	int size;
	string name;
	string unit;
};
