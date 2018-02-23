#ifndef ITEM_H
#define ITEM_H
#include <iostream>

class Item
{
private:

	std::string	name;		// the name of the item
	std::string	unit;		// the unit of measurement

	int	quantity;			// the number of "units" to buy of the "item"

	double unitPrice;		// the cost of the item per unit
public:
	
	Item();															// default constructor
	Item(std::string n, std::string u, int q, double p);			// constructor taking arguments to pass into the private members of Item

	bool operator==(const Item& itm);								// Overload == operator to compare two items

	void setName(std::string n);									// sets the name of an item
	void setUnit(std::string u);									// sets the name of the unit
	void setQuantity(int q);										// sets the quantity of item
	void setUnitPrice(double p);									// sets the unit price of an item

	std::string getName() const;									// returns the name of the item
	std::string getUnit() const;									// returns the unit of the item

	int getQuantity();												// returns the quantity
	double getUnitPrice() const;									// returns the unitPrice

	double extendedPrice();											// returns the extended price of an item given the unitPrice and quantity
};

#endif