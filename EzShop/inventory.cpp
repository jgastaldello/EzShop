#include "inventory.h"


inventory::inventory(void)
{
	size = 0;
	name = "Nothing";
}

inventory::inventory(string n, int s)
{
	size = s;
	name = n;
}

inventory::~inventory(void)
{
}

void inventory::setName(string n)
{
	name = n;
}
void inventory::setSize(int s)
{
	size = s;
}
string inventory::getName() const
{
	return name;
}
int inventory::getSize() const
{
	return size;
}