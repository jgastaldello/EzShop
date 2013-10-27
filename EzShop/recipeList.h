#pragma once
#include "itemList.h"
#include <string>


class recipeList
{
public:
	recipeList(void);
	~recipeList(void);
	void addRecipe(string name);
	void removeRecipe();
	void sortRecipe();
	void saveRecipe();
	void viewRecipe();
	void loadRecipe();
private:
	itemList* recipe;
	string recipeName;
	int arrIndex;// indicate the last element
	int arrSize;// the size of the array
};

