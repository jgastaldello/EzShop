#pragma once
#include "itemList.h"
#include "recipeList.h"
#include <fstream>
#include <iostream>
class shoppingList
{
public:
		//default constructor.... asssume the inventoryList is called inventoryList.csv
        shoppingList(void);
        //overloaded constructor for given the name of inventoryList
        shoppingList(string List);
        ~shoppingList(void);
        // compare the list and add to shopping list
        void compareList(string recipeName);
        //save the list
        void saveList(string fileName);
        //display the list
        void viewList() const;
private:
		//invetory object
        itemList inventory;        
        //shopping list object
        itemList shopList;
        //the target recipe object
        itemList targetList;
        //the recipeList object
        recipeList recipe;
	//name of the inventory List
	string inventoryList;
};

