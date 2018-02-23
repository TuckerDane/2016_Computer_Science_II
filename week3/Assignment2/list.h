#ifndef LIST_H
#define LIST_H

#include "item.h"

class List
{
private:
	Item **itemList;							// a pointer to a dynamic array of pointers to items
	Item *nullItem;								// a pointer to a null Item
	int listSize;								// a variable which tracks the current size of the list

public:
	List();										// a default constructor which initializes the items[] array to 4 dafault items
	~List();									// a destructor used to delete the dynamic item[] array

	void addItem(Item *itm);					// a function which allows the user to add an item to the list
	void removeItem(int num);					// a function which allows the user to remove an item from the numbered list based on its index
	void printItemList();						// a function which prints a numbered list of the items
	
	double totalListPrice();					// a function which returns the total added price of all items in the list
	int checkList(Item *itm);					// a function which checks to see if an item to be added to the list already exists and returns its location
												// in the list. if it does not exist, the function returns -1

	int getListSize();							// a function which returns the size of the list
};

#endif