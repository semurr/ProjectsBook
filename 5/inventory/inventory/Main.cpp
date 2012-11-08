//manage an inventory of a player
#include <iostream>
#include <string>
using namespace std;

//functions
void initialize(const string* container[], int capacity);
bool isFull(const string* const container[], int capacity);
bool isEmpty(const string* const container[], int capacity);
bool Contains(const string* const pItem, const string* const container[], int capacity);
void Display(const string* const container[], int capacity);
void Add(const string* const pItem, const string* const container[], int capacity);
void Remove(const string* const pItem, const string* const container[], int capacity);

int main()
{
	cout <<"\t welcome to my Inventory" << endl;

	//items
	const int items_n = 6;
	const string items[items_n] = {"sword", "Staff", "Bow", "gold", "mana potion", "health potion"};

	//inventory space
	const int inventory_size = 3;
	const string* inventory[inventory_size];
	initialize(inventory, inventory_size);


	//main program

	int choice;
	int itemNumber;

	do
	{

		cout << "Inventory" << endl;
		cout <<"_________" << endl;
		cout << "0 = quit" << endl;
		cout << "1 = Display items" << endl;
		cout << "2 = add item" << endl;
		cout << "3 = remove item" << endl;
		cout << "What would you like to do?: ";
		cin  >> choice;
		cout << endl;

		switch(choice)
		{
		case 0:
			cout << "Thanks for managing your inventory" << endl;
			break;
		case 1:
			cout << "Inventory Items" << endl;
			Display(inventory, inventory_size);
			break;
		case 2:
			for (int i = 0; i < items_n; i++)
			{
				cout << i << " - " << items[i] << endl;
			}

			do
			{
				cout << "Enter the number of the item to add: ";
				cin >> itemNumber;
			}
			while (itemNumber < 0 || itemNumber >= items_n);
			
			Add(&items[itemNumber], inventory, inventory_size);
			break;
		case 3:
			for (int i = 0; i < items_n; i++)
			{
				cout << i << " - " << items[i] << endl;
			}

			do
			{
				cout << "Enter the number of the item you want to get rid off: ";
				cin >> itemNumber;
			}
			while (itemNumber < 0 || itemNumber >= items_n);

			Remove(&items[itemNumber], inventory, inventory_size);
			break;
		default:
			cout << "Sorry please enter a valid choice" << endl;
		}
	} 
	while (choice != 0);

	return 0;

}

//create the initial data
void initialize(const string* container[], int capacity)
{
	for( int i = 0; i < capacity; i ++)
	{
		container[i] = NULL;
	}
}

//checks if the contaier array is full
bool isFull(const string* const container[], int capacity)
{
	bool full = true;
	int i = 0;

	while(full && i<capacity)
	{
		if(container[i] == NULL)
		{
			full = false;
		}

		++i;
	}
	return full;
}

//checks if the container array is empty
bool isEmpty(const string* const container[], int capacity)
{
	bool empty = true;
	int i = 0;

	while(empty && i<capacity)
	{
		if(container[i] != NULL)
		{
			empty = false;
		}

		++i;
	}
	return empty;
}

//check what the contain contains
bool Contains(const string* const pItem, const string* const container[], int capacity)
{
	bool has = false;
	int i = 0;

	while(!has && i<capacity)
	{
		if (container[i] == pItem)
		{
			has = true;
		}
		
		++i;
	}

	return has;
}

//displays the container
void Display(const string* const container[], int capacity)
{
	if(isEmpty(container, capacity))
	{
		cout << "Your invenotry is empty" << endl;
		return;
	}

	for (int i = 0; i < capacity; i++)
	{
		if(container[i] != NULL)
		{
			cout << *(container[i]) << endl;
		}
	}
}

//adds to the container
void Add(const string* const pItem, const string* const container[], int capacity)
{
	if(pItem == NULL)
	{
		return;
	}

	if(Contains(pItem, container, capacity))
	{
		cout << "Item already in invenotry" << endl;
		return;
	}

	if(isFull(container, capacity))
	{
		cout << "Inventory full" << endl;
		return;
	}

	bool found = false;
	int i = 0;

	while (!found  && i < capacity)
	{
		if(container[i] == NULL)
		{
			container[i] = pItem;
		}
		++i;
	}

}

//remove from the container
void Remove(const string* const pItem, const string* const container[], int capacity)
{
	if(pItem == NULL)
	{
		return;
	}

	bool found = false;
	int i = 0;

	while(!found && i < capacity)
	{
		if (container[i] == pItem)
		{
			container[i] = NULL;

			found = true;
		}
		
		++i;
	}

	if(!found)
	{
		cout << "Item was not found" << endl;
	}
}