/*
 *	 Map
 */

#include <iostream>
#include <map>

void ShowInventory(std::map<std::string, int>& inventory)
{
	std::cout << "\nInventory (" << inventory.size() << "):" << std::endl;
	for (const auto& item : inventory)
	{
		std::cout << item.first << ": " << item.second << std::endl;
	}
}

void DeleteItem(std::map<std::string, int>& inventory, const std::string& item)
{
	if (inventory.find(item) != inventory.end())
	{
		inventory.erase(item);
		std::cout << "\n[Info] " << item << " deleted." << std::endl;
	}
	else
	{
		std::cout << "\n[Error] " << item << " not found in inventory." << std::endl;
	}
}

void AddItem(std::map<std::string, int>& inventory, const std::string& item, int quantity)
{
	inventory[item] += quantity;
	std::cout << "\n[Info] " << item << " added to inventory." << std::endl;
}

int main()
{
	std::map<std::string, int> inventory; // item name & quantity
	AddItem(inventory, "Health Potion", 2);
	AddItem(inventory, "Mana Potion", 3);
	AddItem(inventory, "Sword", 1);
	AddItem(inventory, "Shield", 1);
	AddItem(inventory, "Bow", 1);
	AddItem(inventory, "Arrows", 8);
	ShowInventory(inventory);

	DeleteItem(inventory, "Bow");
	DeleteItem(inventory, "Test");
	AddItem(inventory, "Arrows", 4);

	ShowInventory(inventory);
	return 0;
}