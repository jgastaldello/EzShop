#include "recipeList.h"

//consturctor
recipeList::recipeList(void)
{
	vector<list> recipe;
}
//destructor
recipeList::~recipeList(void)
{
	
}
void recipeList:: addRecipe(string name, unsigned long amount, string unit)
{
	//add a recipe(itemList into the recipeList)
	
	//need to check if the item exists already
        list.end();
        list.push_back(item(name, amount, unit));
         //arrList[arrIndex] = item(name, size);
        //arrIndex++;
	
}
void  recipeList:: removeRecipe(string itemName, unsigned long amountToRemove)
{
	//remove a recipe(itemList into the recipeList)
	
	int location = 0;
        //searches for the specified item
        for (unsigned int x = 0; x <= list.size(); x++)
        {
                if (itemName == list[x].getName())
                {
                        location = x;
                        break;
                }
        }
        
        list[location].setAmount(list[location].getAmount() - amountToRemove);
        //arrList[location].setSize(arrList[location].getSize() - numToRemove);

        if (list[location].getAmount() == 0)
        {
                list.erase(list.begin() + location);
                //delete &arrList[location];
        }
	
}
void recipeList:: sortRecipe()
{
	
	for (unsigned int i = 0; i < list.size(); i++)
        {
                string key = list[i].getName();
                //string key = arrList[i].getName();
                //for (int j = i - 1; j >= 0 && (arrList[j].getName()).compare(key) > 0; j--)
                for (int j = i-1; j >= 0 && (list[j].getName()).compare(key) > 0; j--)
                {
                        item temp = list[j + 1];
                        list[j + 1] = list[j];
                        list[j] = temp;
                        /*item temp = arrList[j + 1];
                        arrList[j + 1] = arrList[j];
                        arrList[j] = temp;*/
                }
        }

}
void recipeList:: saveRecipe(string filename)
{
	ofstream myFile;
        fileName.append(".csv");
        cout << "The full filename is " << fileName << "\n";
        myFile.open(fileName);

        for (unsigned int i = 0; i < list.size(); i++)
        {
                myFile << list[i].getName() << " , " << list[i].getAmount() << " , " << list[i].getUnit()<< "\n";
        }
        myFile.close();
}
void recipeList::viewRecipe()
{
	
	//header
        string itemHeader = "Item name", separator = " | ", amountHeader = "Amount", unitHeader = "Units";
        //sets the size as the header itself
        int longestItemName = itemHeader.length(), longestAmountName = amountHeader.length(), longestUnitName = unitHeader.length();
        //total header legnth
        int totalLength = 2 * separator.length();

        for (unsigned int i = 1; i <= 3; i++)
        {
                for (unsigned int x = 0; x < list.size(); x++)
                {
                        string header;
                        int stringLength;
                        if (i == 1)
                        {
                                header = list[x].getName();
                                stringLength = header.length();

                                if (stringLength > longestItemName)
                                {
                                        longestItemName = stringLength;
                                }
                        }
                        else if (i == 2)
                        {
                                header = to_string(list[x].getAmount()); //to_stirng converts number to string
                                stringLength = header.length();

                                if (stringLength > longestAmountName)
                                {
                                        longestAmountName = stringLength;
                                }
                        }
                        else if (i == 3)
                        {
                                header = list[x].getUnit();
                                stringLength = header.length();

                                if (stringLength > longestUnitName)
                                {
                                        longestUnitName = stringLength;
                                }
                        }
                        
                }
        }
        //prints headers
        cout << left;
        cout << setw(longestItemName) << itemHeader << separator;
        cout << setw(longestAmountName) << amountHeader << separator;
        cout << setw(longestUnitName) << unitHeader << "\n";
        totalLength += longestItemName + longestAmountName + longestUnitName;
        for (unsigned int x = 1; x <= totalLength; x++)
        {
                cout << "-";
        }
        cout << "\n";
        //prints all the items in the list
        for (unsigned int x = 0; x < list.size(); x++)
        {
                cout << left << setw(longestItemName) << list[x].getName() << separator;
                cout << right << setw(longestAmountName) << list[x].getAmount() << separator;
                cout << left << setw(longestUnitName) << list[x].getUnit() << "\n";
        }
        for (unsigned int x = 1; x <= totalLength; x++)
        {
                cout << "-";
        }
        cout << "\n";
	
}
void  recipeList::loadRecipe()
{
}
