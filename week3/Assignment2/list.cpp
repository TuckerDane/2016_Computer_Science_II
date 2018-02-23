#include "list.h"
#include <string>

/***************************************************************************************************
**	default constructor
***************************************************************************************************/
List::List()
{
	int num = 4;								// used in case List() were to ever be passed an argument for its default size

	this->itemList = new Item*[num];			// sets itemList pointer to a new dynamically allocated array of pointers to items

	this->nullItem = new Item;					// sets the null pointer to a new default Item

	for (int i = 0; i < num; i++)				// points each element of itemList to nullItem
	{
		this->itemList[i] = nullItem;
	}

	this->listSize = num;
}

/***************************************************************************************************
**	destructor
***************************************************************************************************/
List::~List()
{
	delete nullItem;
	nullItem = NULL;
	delete[] itemList;
	itemList = NULL;
}

/***************************************************************************************************
**	a function which allows the user to add an item to the list
***************************************************************************************************/
void List::addItem(Item *itm)
{
	int num = this->checkList(itm);																				// sets num to the location of the item (if it exitsts on the list) or -1 (if it does not extist on the list)

	if (num > -1)																								// if the item already exists (name, unit, unitprice), add them together
	{
		this->itemList[num]->setQuantity( (this->itemList[num]->getQuantity()) + (itm->getQuantity() ) );		// add the quantities of the item on the list with the item being added 
	}
	else																										// else, add the new item to the list as follows:
	{
		bool listFull = true;																					// a variable that tells if the list is full

		for (int i = 0; i < this->listSize; i++)
		{
			if (this->itemList[i]->getName() == "null")															// if the item slot contains a null item
			{
				this->itemList[i] = itm;																		// replace nullItem in itemList with a pointer to itm
				listFull = false;
				break;
			}
		}

		if (listFull == true)
		{
			this->listSize++;												// increase the size of the list

			Item **tempList;												// create a temporary pointer to a dynamic array of pointers
			tempList = new Item*[this->listSize];							// create the dynamic array of pointers one size larger than the current itemList[] and point tempList to it

			for (int i = 0; i < (this->listSize) - 1; i++)					// fill tempList with pointers to items from itemList
			{
				tempList[i] = this->itemList[i];
			}

			tempList[this->listSize - 1] = itm;								// fill the last slot in tempList with the pointer to the passed in item to be added

			delete[] this->itemList;										// destroy itemList to deallocate the memory it used to store pointers

			this->itemList = new Item*[this->listSize];						// re-allocate memory for itemList with the new listSize

			for (int i = 0; i < (this->listSize); i++)						// fill tempList with pointers to items from itemList
			{
				this->itemList[i] = tempList[i];
			}

			delete[] tempList;												// delete templist
		}
	}
	
}

/***************************************************************************************************
**	a function which allows the user to remove an item from the numbered list based on its index
***************************************************************************************************/
void List::removeItem(int num)
{
	if (itemList[num-1]->getName() != "null")
	{
		for (int i = (num-1); i < (this->listSize - 1); i++)		// point each item pointer in itemList (from num to listSize-1)
		{
			itemList[i] = itemList[i+1];							// reset the pointer to the pointer to its right
		}
		itemList[listSize-1] = nullItem;							// set the final item pointer in itemList to nullItem;
		listSize--;
	}
	else
	{
		std::cout << "No item exists for this item number!" << std::endl << std::endl;
	}
}

/***************************************************************************************************
**	a function which prints a numbered list of the items
***************************************************************************************************/
void List::printItemList()
{
	for (int i = 0; i < this->listSize; i++)
	{
		if (this->itemList[i]->getName() != "null")
		{
			std::cout << i + 1 << ": " << this->itemList[i]->getName() << std::endl;
			std::cout << "\t Quantity: " << this->itemList[i]->getQuantity() << " " << this->itemList[i]->getUnit() << "(s)" << std::endl;
			std::cout << "\t Cost per " << this->itemList[i]->getUnit() << ": " << this->itemList[i]->getUnitPrice() << std::endl;
			std::cout << "\t Total cost for " << this->itemList[i]->getQuantity() << ": " << this->itemList[i]->extendedPrice() << std::endl;
		}
	}
}

/***************************************************************************************************
**	a function which returns the total added price of all items in the list
***************************************************************************************************/
double List::totalListPrice()
{
	double tlp = 0;										// total list price initialized to zero

	for (int i = 0; i < listSize; i++)					// for each item in the list
	{
		tlp += itemList[i]->extendedPrice();			// add the extended price to the total list price
	}

	return tlp;											// return the total list price
}

/***************************************************************************************************
**	a function which returns the size of the list
***************************************************************************************************/
int List::getListSize()
{
	return listSize;
}

/***************************************************************************************************
**	a function which checks to see if an item to be added to the list already exists and returns 
**	its locaiton in the list. if it does not exist, the function  returns -1
***************************************************************************************************/
int List::checkList(Item *itm)
{
	for (int i = 0; i < this->listSize; i++)
	{
		if (itemList[i] == itm)
		{
			return i;
		}
	}

	return -1;
}