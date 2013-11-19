#include <string>
#include "itemList.h"
#pragma once
class recipeList
{
public:
	//constructor
	recipeList(void);
	//destructor
	~recipeList(void);
	//add a new recipe to the recipe list
	void addRecipe(string name);
	//remove a recipe from the list and the file
	void removeRecipe(string name);
	//re-order the list in alphabetical order 
	void sortRecipe();
	//save the recipeList into recipeList.csv
	void saveRecipe();
	//display the all of the recipe
	void viewRecipe();
	//display specific recipe
	void viewRecipe(string name);
	//load a recipe
	bool loadRecipe();
	//search a recipe from the list
	int searchRecipe(string target) const;
	//is the recipeList empty
	bool isEmpty() const;
	//not supported yet....
	//... not sure if we need it
	void createRecipe(string name);
	
private:
	//name of the recipes
	vector<string> recipe;	
};
