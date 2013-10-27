#include "recipeList.h"

//consturctor
recipeList::recipeList(void)
{
	recipe =  new itemList [10];
	arrIndex = 0;// indicate the last element
	arrSize = 10;// the size of the array
}
//destructor
recipeList::~recipeList(void)
{
	delete[] recipe;
}
void recipeList:: addRecipe(string name)
{
	//add a recipe(itemList into the recipeList)
}
void  recipeList:: removeRecipe()
{
	//remove a recipe(itemList into the recipeList)
}
void recipeList:: sortRecipe()
{
}
void recipeList:: saveRecipe()
{
}
void recipeList::viewRecipe()
{
}
void  recipeList::loadRecipe()
{
}
