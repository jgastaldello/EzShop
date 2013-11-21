#include "shoppingList.h"

using namespace std;
//default constructor
//...opening the required file
shoppingList::shoppingList(void)
{
	//name of the list is	
	inventoryList = "inventory.csv";
	//load the inventory and recipeList
	inventory.openList("inventory.csv");
	//load the RecipeList
	recipe.loadRecipe();
	//construct a shopList as itemList
	shopList = itemList();
	
}
//overloaded constructor
//...opening the required file and requires the fileName of inventoryList
shoppingList::shoppingList(string List)
{
	//name of the list is
	inventoryList = List;
	//load the inventory and recipeList
	inventory.openList(inventoryList);
	recipe.loadRecipe();
	//construct a shopList as itemList
	shopList = itemList();
	
}
shoppingList::~shoppingList(void)
{
}

//compare the recipe and inventory, then generate a shopping list
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
	for (int t = 0 ; t < targetList.list.size(); t++)
	{
		int iLocation = inventory.searchList(targetList.list[t].getName());
		if (iLocation == -1)
		{
			//this item is not on the inventory list
			//... add to shopping list
			shopList.addListItem(targetList.list[t].getName(),targetList.list[t].getAmount(),targetList.list[t].getUnit());
		}else{
			//this item is on the inventory list 
			//... check are there enough amount of it
			if(inventory.list[iLocation].getUnit()!=targetList.list[t].getUnit())
			{	
				//we have different Unit
				//need to change the unit
				int iAmount = inventory.list[iLocation].getAmount();
				int tAmount = targetList.list[t].getAmount();
				string iUnit =inventory.list[iLocation].getUnit();
				string tUnit =targetList.list[t].getUnit();
				if (iUnit == "kg" && tUnit == "g" || iUnit == "L" && tUnit == "mL")
				{
					iAmount	*= 1000;
					inventory.list[iLocation].setAmount(iAmount);
					inventory.list[iLocation].setUnit(tUnit);

				}else if (iUnit == "g" && tUnit == "kg" || iUnit == "mL" && tUnit == "L")
				{
					tAmount	*= 1000;
					targetList.list[t].setAmount(tAmount);
					targetList.list[t].setUnit(iUnit);	

				}else{
					cout<< "SORRY: Item is found but with different Unit, still add it into shopping list \n";
					shopList.addListItem(targetList.list[t].getName(),targetList.list[t].getAmount(),targetList.list[t].getUnit());
					return;
				}

			}
			if(inventory.list[iLocation].getAmount()>=targetList.list[t].getAmount())
			{
				//inventory has more than enough of it
				//...take them out from the inventory				
				inventory.removeListItem(targetList.list[t].getName(),targetList.list[t].getAmount());
								
			}else{
				//inventory does NOT have enough of it
				//...take them out from the inventory
				int newAmount = targetList.list[t].getAmount()-inventory.list[iLocation].getAmount();
				inventory.removeListItem(targetList.list[t].getName(),inventory.list[iLocation].getAmount());
				shopList.addListItem(targetList.list[t].getName(), newAmount ,targetList.list[t].getUnit());
			}
		}

	}
	inventory.list.end();
	inventory.sortList();
	//remove .csv for the file name
	string delimiter = ".csv";
	string noCsv = inventoryList.substr(0, inventoryList.find(delimiter));	
	//update your inventory
	inventory.saveList(noCsv);	
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
