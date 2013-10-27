#include "item.h"

//constuctor
item::item(void)
{
	size = 0;
	name = " ";
}
item::item(string n, int s, string u)
{
	size = s;
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
void item::setSize(int s)
{
	size = s;
}
void item::setUnit(string u)
{
	unit = u;
}
string item::getName() const
{
	return name;
}
int item::getSize() const
{
	return size;
}
string item::getUnit() const
{
	return unit;
}