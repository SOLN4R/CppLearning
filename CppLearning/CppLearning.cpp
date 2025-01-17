/*
 *	 Simple inventory system (fixed)
 */

#include <iostream>
#include <string>
#include <limits>


const int MAX_INVENTORY_SIZE = 100;

class Inventory
{
private:
	std::string* _items;
	int _current_size;
	const int _max_size;
public:
	Inventory(const int max_size) : _max_size(max_size)
	{
		_items = new std::string[max_size];
		_current_size = 0;
		std::cout << "[Core] An inventory with a size of " << _max_size << " has been created." << std::endl;
	}

	~Inventory() 
	{
		delete[] _items;
		_items = nullptr;
		std::cout << "[Core] The inventory has completed its work and cleared the memory." << std::endl;
	}

	void AddItem(const std::string& item)
	{
		if (_current_size >= _max_size)
		{
			std::cout << "[Error] There is no space in the inventory." << std::endl;
			return;
		}
		_items[_current_size] = item;
		_current_size++;
		std::cout << "[Info] " << item << " has been added to the inventory." << std::endl;
	}

	void RemoveItem(const std::string& item)
	{
		bool is_found = false;

		for (int i = 0; i < _current_size; i++)
		{
			if (is_found) 
			{
				_items[i - 1] = _items[i];
				continue;
			}

			if (_items[i] == item) 
			{
				is_found = true;
			}
		}

		if (is_found)
		{
			_current_size--;
			_items[_current_size].clear();
			std::cout << "[Info] The " << item << " item has been deleted." << std::endl;
			return;
		}
		std::cout << "[Error] The item was not found." << std::endl;
	}

	void ShowInventory() const
	{
		std::cout << "Inventory:" << std::endl;
		for (int i = 0; i < _current_size; i++)
		{
			std::cout << i + 1 << ". " << _items[i] << std::endl;
		}
	}

	bool IsEmpty() const
	{
		return _current_size == 0;
	}

	bool IsFull() const
	{
		return _current_size == _max_size;
	}
};

int InputPositiveNumber(const std::string& message, const int max_number)
{
	int number;

	while (true) {
		std::cout << message;
		std::cin >> number;

		if (std::cin.fail() || number < 1 || number > max_number)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "[Error] Invalid input." << std::endl;
			continue;
		}
		return number;
	}
	
}

int main()
{
	enum inventory_menu
	{
		ADD_ITEM = 1,
		REMOVE_ITEM,
		SHOW_INVENTORY,
		EXIT
	};

	std::cout << "Welcome to simple inventory system." << std::endl;
	int inventory_size = InputPositiveNumber("\nEnter maximum inventory size: ", MAX_INVENTORY_SIZE);
	Inventory inventary(inventory_size);

	bool is_running = true;
	while (is_running)
	{
		std::cout << "\nInventory menu:" << std::endl;
		std::cout << ADD_ITEM << ". Add item" << std::endl;
		std::cout << REMOVE_ITEM << ". Remove item" << std::endl;
		std::cout << SHOW_INVENTORY << ". Show inventory" << std::endl;
		std::cout << EXIT << ". Exit" << std::endl;

		int choice = InputPositiveNumber("\n> ", EXIT);
		switch (choice)
		{
		case ADD_ITEM:
		{
			if (inventary.IsFull()) 
			{
				std::cout << "[Info] The inventory is full." << std::endl;
				break;
			}
			std::string item;
			std::cout << "> Enter item name: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, item);
			inventary.AddItem(item);
			break;
		}
		case REMOVE_ITEM:
		{
			if (inventary.IsEmpty()) 
			{
				std::cout << "[Info] The inventory is empty." << std::endl;
				break;
			}
			std::string item;
			std::cout << "> Enter item to remove: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, item);
			inventary.RemoveItem(item);
			break;
		}
		case SHOW_INVENTORY:
		{
			if (inventary.IsEmpty()) 
			{
				std::cout << "[Info] The inventory is empty." << std::endl;
				break;
			}
			inventary.ShowInventory();
			break;
		}
		case EXIT:
		{
			is_running = false;
			break;
		}
		default:
			std::cout << "[Error] Exiting the menu range." << std::endl;
			break;
		}
	}
	return 0;
}