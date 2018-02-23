#include "item.h"
#include "list.h"
#include "InputValidation.h"
#include <string>
#include <limits>

/***************************************************************************************************
**	TEST METHODS
***************************************************************************************************/
/*
void printCheckList(List &lst, Item &itm)
{
	std::cout << "checking to see if " << itm.getName() << " is on the list" << std::endl;
	if (lst.checkList(&itm) == -1)
	{
		std::cout << itm.getName()  << " is not on the list" << std::endl << std::endl;
	}
	else
	{
		std::cout << itm.getName() << " is number " << lst.checkList(&itm) + 1 << " on the list!" << std::endl << std::endl;
	}
}
*/

/***************************************************************************************************
**	MAIN FUNCTION
***************************************************************************************************/
int main()
{
	// TEST TO ENSURE ITEM CLASS WORKS PROPERLY
	/*
	Item pineapple("pineapple", "fruit", 5, 25.14);

	std::cout << "I just bought " << pineapple.getQuantity() << " " << pineapple.getUnit() << "s of " << pineapple.getName() << "!!" << std::endl;
	std::cout << "It cost me " << pineapple.extendedPrice() << " because it cost " << pineapple.getUnitPrice() << " dollars for a single " << pineapple.getName() << "!" << std::endl << std::endl;
	*/

	// TEST TO ENSURE THE LIST CLASS WORKS PROPERLY
	/*
	//	Create instances of items
	Item turtle("turtle", "turtle", 1, 20);
	Item cheese("cheese", "oz", 1, 0.5);
	Item milk("milk", "gallon", 1, 4.50);
	Item coffee("coffee", "bag", 1, 5);
	Item aarow("aarow", "quiver", 1, 15);	// create two items with the same name but different quantity types to test if they get duplicated
	Item aarow2("aarow", "coolguy", 1, 1);

	// Create an instance of a list
	List groceryList;

	// Add a number of existing items to the list
	groceryList.addItem(&turtle);
	groceryList.addItem(&cheese);
	groceryList.addItem(&milk);
	groceryList.addItem(&aarow);
	groceryList.addItem(&aarow2);

	// Print out the grocery list to ensure that it is working properly and items were added
	std::cout << "Grocery List:" << std::endl;
	groceryList.printItemList();
	std::cout << std::endl;

	// test to ensure the total price is printed correctly
	std::cout << "the total list price is: ";
	std::cout << groceryList.totalListPrice() << std::endl;
	std::cout << std::endl;

	// run the printCheckList function to ensure the checkList funciton works properly
	printCheckList(groceryList, coffee);
	printCheckList(groceryList, milk);
	printCheckList(groceryList, aarow2);
	printCheckList(groceryList, cheese);

	// ensure item removal from the list works properly by removing items then checking the list
	std::cout << "removing cheese" << std::endl;
	groceryList.removeItem(2);
	groceryList.printItemList();
	std::cout << std::endl;
	std::cout << "the total list price is: ";
	std::cout << groceryList.totalListPrice() << std::endl;
	std::cout << std::endl;

	printCheckList(groceryList, cheese);

	std::cout << "removing milk" << std::endl;
	groceryList.removeItem(2);
	groceryList.printItemList();
	std::cout << std::endl;
	std::cout << "the total list price is: ";
	std::cout << groceryList.totalListPrice() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	// ensure addItem is still working
	groceryList.addItem(&turtle);
	groceryList.printItemList();
	std::cout << std::endl;
	std::cout << "the total list price is: ";
	std::cout << groceryList.totalListPrice() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	*/
	std::cout << "You are about to make a grocery list of items to buy." << std::endl << std::endl;

	int numItems;		//	the number of items the user is entering into the list
	List userList;		// create a user-defined list

	int choice;
	bool end = false;
	while (end == false)
	{
		std::cout << "1: Add Items to List" << std::endl;
		std::cout << "2: Remove Items from List" << std::endl;
		std::cout << "3: Display List" << std::endl;
		std::cout << "4: Quit" << std::endl << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		std::cout << std::endl << std::endl;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid choice. Please try again" << std::endl << std::endl;
			continue;
		}

		// Add items to list
		if (choice == 1)
		{
			std::cout << "How many items would you like to enter onto the list? ";
			std::cin >> numItems;

			boundsValidation(numItems, 1, 100);
			Item *userInput = new Item[numItems];

			std::cout << "Enter " << numItems << " items to add to the list: " << std::endl << std::endl;

			for (int i = 0; i < numItems; i++)
			{
				std::string name;
				std::string unit;
				int quantity;
				double unitPrice;

				std::cout << "Item " << i + 1 << std::endl;

				std::cout << "\t Name: ";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, name);

				userInput[i].setName(name);

				std::cout << "\t Unit: ";
				std::getline(std::cin, unit);

				userInput[i].setUnit(unit);

				std::cout << "\t Quantity: ";
				std::cin >> quantity;

				quantity = boundsValidation(quantity, 0, 100000);
				userInput[i].setQuantity(quantity);

				std::cout << "\t Unit Price: ";
				std::cin >> unitPrice;

				unitPrice = boundsValidation(unitPrice, 0.0, 100000.0);
				userInput[i].setUnitPrice(unitPrice);

				userList.addItem(&userInput[i]);
				std::wcout << std::endl << std::endl;
			}
		}

		// Remove items from list
		else if (choice == 2)
		{
			int itemNumber;
			std::cout << "What item number do you want to remove from the list? (enter the item number) ";
			std::cin >> itemNumber;

			itemNumber = boundsValidation(itemNumber, 1, userList.getListSize());

			userList.removeItem(itemNumber);
		}

		// Display List
		else if (choice == 3)
		{
			std::cout << "Here is your list: " << std::endl << std::endl;
			userList.printItemList();
			std::cout << std::endl << "The total price of this list is: " << userList.totalListPrice() << std::endl << std::endl;
		}

		// Quit
		else if (choice == 4)
		{
			end = true;
		}

		// Input Validation
		else
		{
			std::cout << "Invalid choice. Please try again." << std::endl << std::endl;
		}
	}

	return 0;
}