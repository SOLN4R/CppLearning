/*
 *	 Basics of OOP: creating classes, objects and encapsulation
 */

#include <iostream>

class Character
{
public:
	std::string name;
private:
	int _health = 100;
	int _level = 1;

public:
	void TakeDamage(int damage)
	{
		if (damage <= 0) {
			std::cout << "[Error] The damage must be greater than 0." << std::endl;
			return;
		}

		_health = std::max(0, _health -= damage);
		
		if (_health <= 0) {
			std::cout << "[Info] " << name << "'s character is destroyed." << std::endl;
		}
		else {
			std::cout << "[Info] " << name << "'s character took damage of " << damage << "." << std::endl;
		}
	}

	void Heal(int amount)
	{
		if (amount <= 0) {
			std::cout << "[Error] The heal amount must be greater than 0." << std::endl;
			return;
		}

		_health = std::min(100, _health += amount);
		std::cout << "[Info] " << name << "'s character's health has been increased to " << _health << "." << std::endl;
	}
	
	void DisplayStatus()
	{
		if (name.empty()) {
			std::cout << "[Error] Name cannot be empty!" << std::endl;
			return;
		}

		std::cout << "Character:" << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Health: " << _health << std::endl;
		std::cout << "Level: " << _level << std::endl;
	}
};

int main()
{
	Character warrior;
	Character magician;

	warrior.DisplayStatus();

	warrior.name = "Warrior";
	magician.name = "Magician";

	warrior.DisplayStatus();
	warrior.TakeDamage(20);
	warrior.Heal(10);
	warrior.DisplayStatus();

	magician.DisplayStatus();
	magician.TakeDamage(50);
	magician.Heal(20);
	magician.DisplayStatus();
	return 0;
}