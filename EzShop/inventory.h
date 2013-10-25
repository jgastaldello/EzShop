#pragma once

#include <string>

using namespace std;

class inventory
{
	public:
		inventory(void);
		inventory(string n, int s);
		~inventory(void);
		void setName(string n);
		void setSize(int s);
		string getName() const;
		int getSize() const;
	private:
		int size;
		string name;
};

