#include "shoppingList.h"

using namespace std;
shoppingList::shoppingList(void)
{
	//load the inventory and recipeList
	inventory.openList("inventory.csv");
	recipe.loadRecipe();
	//construct a shopList as itemList
	shopList = itemList();
}
shoppingList::shoppingList(string inventoryList)
{
	//load the inventory and recipeList
	inventory.openList(inventoryList);
	recipe.loadRecipe();
	//construct a shopList as itemList
	shopList = itemList();
}
shoppingList::~shoppingList(void)
{

}
void shoppingList::compareList(string recipeName)
{

	//open the recipe
	if (recipe.searchRecipe(recipeName) == -1)
	{
		cout<< recipeName << " not found.\n" ;
		return;
	}else{
		targetList.openList(recipeName);
	}

	//to compare the items on the recipe with inventory list

	for (int i = 0 ; i < targetList.size(); i++)
	{
		if (inventory.searchList(targetList.list[i].getName()) == -1)
		{
			//this item is not on the inventory list
			//... add to shopping list
			shopList.addListItem(targetList.list[i].getName(),targetList.list[i].getAmount(),targetList.list[i].getUnit());
		}else{
			//this item is on the inventory list 
			//... check are there enough amount of it
			if(inventory.list[i].getUnit()==targetList.list[i].getUnit()){
				if(inventory.list[i].getAmount()>=targetList.list[i].getAmount())
				{
					//inventory has more than enough of it
					//...take them out from the inventory
					int newAmount = inventory.list[i].getAmount()-targetList.list[i].getAmount();
					if (newAmount > 0)
					{
						inventory.removeListItem(targetList.list[i].getName(),newAmount);
					}
				}
			}else{
				//we have different Unit
				cout<< "SORRY: Item is found but with different Unit, still add it into shopping list \n";
				shopList.addListItem(targetList.list[i].getName(),targetList.list[i].getAmount(),targetList.list[i].getUnit());
			}
		}
		
	}
}

void shoppingList::saveList(string fileName)
{
	//save the shopping list
	shopList.saveList(fileName);
}
void shoppingList::viewList() const
{
	//view the shopping list
	cout<< "Shopping List: \n";
	shopList.viewList();
}
