#include <string>
#include "itemList.h"
#pragma once
class recipeList
{
public:
	recipeList(void);
	~recipeList(void);
	void addRecipe(string name);
	void removeRecipe(string name);
	void sortRecipe();
	void saveRecipe();
	void viewRecipe();
	void viewRecipe(string name);
	bool loadRecipe();
	int searchRecipe(string target) const;
	
private:
	vector<string> recipe;
	string recipeName;

	
};

