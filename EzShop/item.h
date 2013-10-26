#pragma once
#include <string>
using namespace std;

class item
{
	public:
		item(void);
		item(string n, int s);
		~item(void);
		void setName(string n);
		void setSize(int s);
		string getName() const;
		int getSize() const;
	private:
		int size;
		string name;
};
