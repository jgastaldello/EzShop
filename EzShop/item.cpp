#include "item.h"

//constuctor
item::item(void)
{
	amount = 0;
	name = " ";
}
item::item(string n, unsigned long s, string u)
{
	amount = s;
	name = n;
	unit = u;
}
//destructor
item::~item(void)
{

}
void item::setName(string n)
{
	name = n;
}
void item::setAmount(int s)
{
	amount = s;
}
void item::setUnit(string u)
{
	unit = u;
}
string item::getName() const
{
	return name;
}
unsigned long item::getAmount() const
{
	return amount;
}
string item::getUnit() const
{
	return unit;
}