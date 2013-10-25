#include <string>
#include "itemList.h"
#pragma once
class recipeList
{
public:
	recipeList(void);
	~recipeList(void);
	void addRecipe(string name);
	void removeRecipey();
	void sortRecipe();
	void saveRecipe();
	void viewRecipe();
	void loadRecipe();
private:
	itemList recipe;
	string recipeName;
	
};

