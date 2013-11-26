/*
CMPT 106 Group Project:
EzShop: Shopping, Simplified!
Created by: Joshua Gastaldello, Arthur Chu, Karen Li, Ryan Bosley, 
			Vikash Ahir, Erick Liamzon, Grant Wallis and Ravdeep Khangura
*/

#include "itemList.h"
#include "item.h"
#include "recipeList.h"
#include "shoppingList.h"
#include "recipeList.cpp"
#include "shoppingList.cpp"
#include <iostream>
#include <limits.h>

string invName;

void mainMenu(bool listSaved, itemList &inventoryList);

void displayInventory(itemList &inventoryList);
void manageInventory(bool listSaved, itemList &inventoryList, recipeList &rList);
void addToInventory(itemList &inventoryList);
void removeFromInventory(itemList &inventoryList);

void manageRecipes(bool listSaved, itemList &inventoryList);
void addRecipes(recipeList &rList);
void removeFromRecipe(recipeList &rList);
void displayRecipe(recipeList &rList);

void createShoppingList(bool listSaved, itemList &inventoryList);

bool yesOrNo();
int numberRangeChoice(int min, int max);
void chooseFile(itemList &list);
void start(itemList &inventoryList, bool &choice);


int main()
{
	itemList inventoryList;

	bool listSaved = false;
	start(inventoryList,listSaved);
	cout << "\n";

	mainMenu(listSaved, inventoryList);


	system("pause");
	return 0;
}

//displays welcome and opens existing inventory
void start(itemList &inventoryList, bool &choice)
{
	cout << "*********************************\n";
	cout << "Welcome to EzShop!\n";
	cout << "*********************************\n";
	cout << "\n";

	cout << "Would you like to open an existing inventory? ";
	choice = yesOrNo();

	if (choice)
	{
		chooseFile(inventoryList);
	}
}

// Main menu
void mainMenu(bool listSaved, itemList &inventoryList)
{
	int totalMenuItems = 0;		// user options

	cout << "\nMain Menu\n";
	cout << "-----------------------\n";

	cout << ++totalMenuItems << ": Manage inventory\n";
	cout << ++totalMenuItems << ": Manage recipes\n";
	cout << ++totalMenuItems << ": Create shopping list\n";
	cout << ++totalMenuItems << ": Quit" << endl;

	cout << "\nChoose a task: ";
	int task = numberRangeChoice(1, totalMenuItems);
	cout << "\n";

	recipeList rList;

	switch (task)
	{
	case 1:
		//manage inventory
		manageInventory(listSaved, inventoryList, rList);
		break;
	case 2:
		//manage recipes
		manageRecipes(listSaved, inventoryList);
		break;
	case 3:
		//create shopping list
		createShoppingList(listSaved, inventoryList);

		break;;
	case 4:
		//Quit
		exit(1);
		break;
	default:
		cout << "Error: MENU default case\n";
		break;
	}
}

//manage inventory
void manageInventory(bool listSaved, itemList &inventoryList, recipeList &rList) {
	int inventoryOptions;		// user options
	bool cont = 1;

	while (cont){
		cout << "\nInventory Menu\n";
		cout << "-----------------------\n";

		inventoryOptions = 0;
		cout << ++inventoryOptions << ": Add item to inventory\n";
		cout << ++inventoryOptions << ": Remove item from inventory\n";
		cout << ++inventoryOptions << ": Display inventory\n";
		cout << ++inventoryOptions << ": Go back\n";

		cout << "\n";
		cout << "Choose a task: ";
		int task = numberRangeChoice(1, inventoryOptions);
		cout << "\n";


		// Adding to inventory
		if (task == 1) {
			addToInventory(inventoryList);
			inventoryList.sortList();
			inventoryList.saveList("inventory");
		}
		// Removing from inventory
		else if (task == 2){
			removeFromInventory(inventoryList);
			inventoryList.sortList();
			inventoryList.saveList("inventory");
		}
		// Display ingredients in inventory
		else if (task == 3){
			displayInventory(inventoryList);
		}
		// Go back to main menu
		else if (task == 4){
			cont = 0;
			mainMenu(listSaved, inventoryList);
		}
	}

}

// Add to inventory
void addToInventory(itemList &inventoryList)
{
	bool contInput = 1;
	while (contInput) {
		cout << "Enter an item name: ";
		string name = " ";
		cin >> name;

		cout << "Enter the item amount: ";
		unsigned int amount = 0;
		cin >> amount;

		cout << "Enter the item unit: ";
		string unit = " ";
		cin >> unit;

		// Check for correct units
		while ((unit != "g") && (unit != "kg") && (unit != "mL") && (unit != "L"))
		{
			cout << "Sorry: This item will be not added\n";
			cout << "  *TYPE: The unit "" << unit << "" is not supported in this program.\n";
			cout << "  *Please convert your unit in terms of g, kg, mL, or L.\n";

			cout << "Re-enter the item unit: ";
			cin >> unit;
		}

		inventoryList.addListItem(name, amount, unit);

		cout << "Would you like to input another item? ";
		bool choice = yesOrNo();
		contInput = choice;
	}
}

// Remove from inventory
void removeFromInventory(itemList &inventoryList)
{
	bool contInput = 1;
	while (contInput) {
		cout << "Enter an item name: ";
		string name = " ";
		cin >> name;

		cout << "Enter the amount to remove: ";
		unsigned int amount = 0;
		cin >> amount;

		inventoryList.removeListItem(name, amount);

		cout << "Would you like to remove another item? ";
		bool choice = yesOrNo();
		contInput = choice;
	}
}

// Prints the inventory list
void displayInventory(itemList &inventoryList)
{
	cout << "\nHere is your current inventory:\n\n";
	inventoryList.viewList();
	cout << "\n";
}

// Manage recipe
void manageRecipes(bool listSaved, itemList &inventoryList) {
	int recipeOptions;		// user options
	bool cont = 1;
	recipeList rList = recipeList();

	cout << "Do you have a recipe list?\n";
	if (yesOrNo()){
		rList.loadRecipe();
	}

	while (cont){
		cout << "\nRecipe Menu\n";
		cout << "-----------------------\n";

		recipeOptions = 0;
		cout << ++recipeOptions << ": Add a recipe\n";
		cout << ++recipeOptions << ": Remove a recipe\n";
		cout << ++recipeOptions << ": Display a specific recipe\n";
		cout << ++recipeOptions << ": Display all recipes\n";
		cout << ++recipeOptions << ": Go back\n";

		cout << "\n";
		cout << "Choose a task: ";
		int task = numberRangeChoice(1, recipeOptions);
		cout << "\n";


		// Adding recipe
		if (task == 1) {
			addRecipes(rList);
			rList.sortRecipe();
			rList.saveRecipe();
		}
		// Removing recipe
		else if (task == 2){
			removeFromRecipe(rList);
			rList.sortRecipe();
			rList.saveRecipe();
		}
		// Display recipe
		else if (task == 3){
			displayRecipe(rList);
		}
		else if (task == 4){
			rList.viewRecipe();
		}
		// Go back to main menu
		else if (task == 5){
			cont = 0;
			mainMenu(listSaved, inventoryList);
		}
	}

}

// Add recipe
void addRecipes(recipeList &rList)
{
	bool contInput = 1;
	while (contInput) {
		cout << "Enter the recipe name: ";
		string name = " ";
		cin >> name;

		rList.addRecipe(name);

		cout << "Would you like add another recipe? ";
		bool choice = yesOrNo();
		contInput = choice;
	}
}

// Remove recipe
void removeFromRecipe(recipeList &rList)
{
	bool contInput = 1;
	while (contInput) {
		cout << "Enter the recipe name: ";
		string name = " ";
		cin >> name;

		rList.removeRecipe(name);

		cout << "Would you like to remove another recipe? ";
		bool choice = yesOrNo();
		contInput = choice;
	}
}

// Display recipe
void displayRecipe(recipeList &rList)
{
	string rName = " ";
	cout << "Enter your recipe name: ";
	cin >> rName;

	cout << "\nHere is your recipe:\n\n";
	rList.viewRecipe(rName);
	cout << "\n";
}

// Shopping list
void createShoppingList(bool listSaved, itemList &inventoryList)
{
	shoppingList sList = shoppingList();
	cout << "Enter a recipe: ";
	string name = " ";
	cin >> name;

	sList.compareList(name);
	sList.viewList();

	cout << "Do you want to save this shopping list? ";
	if (yesOrNo()){
		cout << "Choose a name: ";
		string sName;
		cin >> sName;
		sList.saveList(sName);
	}

	mainMenu(listSaved, inventoryList);
}

// Gets a Y or N input and returns T or F
bool yesOrNo()
{
	string input;
	cout << "(Y or N) ";
	cin >> input;
	while ((input != "Y") && (input != "y") && (input != "N") && (input != "n"))
	{
		cout << "Invalid input. Try again: ";
		cin >> input;
	}
	cin.sync();
	return ((input == "Y") || (input == "y"));
}

// Asks user for number between the specified range
int numberRangeChoice(int min, int max)
{
	int input;
	cout << "("<<min<<" to "<<max<<") ";
	cin >> input;
	while (input < min || input > max)
	{
		cout << "Invalid input. Try again: ";
		cin >> input;
	}
	cin.sync();
	return input;
}

// Opens an inventory file
void chooseFile(itemList &list)
{
	// Asks for file name
	string fileName;
	cout << "\nEnter your file name (with extension): "; 
	getline(cin, fileName);
	bool check = list.openList(fileName);

	// If file name is invalid, continues to ask for file name
	while (!check)
	{
		string fileName;
		cout << "\nEnter your file name (with extension): ";
		getline(cin, fileName);
		if (list.openList(fileName)){
			check = 1;
		}
		
	}
	invName = fileName;
}
