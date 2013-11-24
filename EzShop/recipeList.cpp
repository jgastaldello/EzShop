#include "recipeList.h"
#include <fstream>
#include <iostream>
#include <iomanip> //cout setw()
#include <algorithm> //std::find
#include <stdio.h>

using namespace std;
//constructor
recipeList::recipeList(void)
{
	vector<string> recipe;
}
//destructor
recipeList::~recipeList(void)
{
}
//not supported yet....
//... not sure if we need it
//.......create a recipe from empty
void recipeList:: createRecipe(string name)
{
	cout<<" \n\n\n\nThis is not supported at all\n\n\n\n";
}

void recipeList:: addRecipe(string name)
{
	//save the recipe on the list	
	int location = searchRecipe(name);
	if (location == -1){
		//try to open it
		//load it
		ifstream ist(name.c_str()); // open file
		// Check if file opened correctly
		if (ist.fail())
		{
			cout << "Recipe: "<<name<< " not found\n";
			return;
		}

		recipe.end();
		recipe.push_back(name);
	}else{
		cout<< name << " is on the recipeList already." <<"\n";
	}

}
//remove a recipe from the list and the file
void  recipeList:: removeRecipe(string name)
{
	int location = searchRecipe(name);	
	recipe.erase(recipe.begin() + location);
	
	//http://www.cplusplus.com/reference/cstdio/remove/
	if(remove(name.c_str()) != 0 ){
		perror( "Error deleting file \n");
	}else{
		puts( "File successfully deleted" );
	}
	
 
}
	//re-order the list in alphabetical order 
void recipeList:: sortRecipe()
{
	//just sort it
	for (unsigned int i = 0; i < recipe.size(); i++)
	{
		string key = recipe[i];		 
		for (int j = i-1; j >= 0 && (recipe[j]).compare(key) > 0; j--)
		{
			string temp = recipe[j + 1];
			recipe[j + 1] = recipe[j];
			recipe[j] = temp;			
		}
	}
}
//save the recipeList into recipeList.csv
void recipeList:: saveRecipe()
{
	string fileName = "recipeList";
	//update the file
	ofstream myFile;
	fileName.append(".csv");
	cout << "The full filename is " << fileName << "\n";
	myFile.open(fileName);

	for (unsigned int i = 0; i < recipe.size(); i++)
	{
		myFile << recipe[i]<< "\n";
	}
	myFile.close();
}
//display the all of the recipe
void recipeList::viewRecipe()
{
	//view them	
	for ( int i = 0 ; i < recipe.size() ; i++)
	{
		viewRecipe(recipe[i]);
	}

}
//display specific recipe (given the name of the recipe)
void recipeList::viewRecipe(string name)
{
	//view it
	//header	
	cout << "Recipe name: " << name <<" \n";
	//view the file
	itemList tmpRecipe;
	tmpRecipe.openList(name);
	tmpRecipe.viewList();
	

}
//load a recipe
bool recipeList::loadRecipe()
{
	string fileName = "recipeList.csv";
	//load it
	ifstream ist(fileName.c_str()); // open file
	// Check if file opened correctly
	if (ist.fail())
	{
		cout << "File : "<<fileName<<" not found\n";
		return false;
	}	
	string recipeName;

	while (ist >> recipeName)
	{		
		addRecipe(recipeName);
	}

	return true; //return true if the file exists, false if it doesn't
}
//search a recipe from the list, return -1 if not finding it
int recipeList::searchRecipe(string target) const
{
	for (int i = 0; i < recipe.size() ; i++)
	{
		string item = recipe[i];
		if (item == target)
		{
			return i;
		}
	}
	return -1;
}
//check if the recipeList empty
bool recipeList::isEmpty() const
{
	return (recipe.size() == 0);
}

