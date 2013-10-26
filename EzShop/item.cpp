#include "item.h"

item::item(void)
{
	size = 0;
	name = "Nothing";
}

item::item(string n, int s)
{
	size = s;
	name = n;
}

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
string item::getName() const
{
	return name;
}
int item::getSize() const
{
	return size;
}