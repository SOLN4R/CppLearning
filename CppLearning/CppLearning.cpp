/*
 *	 Basics of OOP: constructors
 */

#include <iostream>

class Character
{
private:
	std::string _name;
	int _health;
	int _level;

public:
	Character(const std::string& name, int health, int level) : _name(name), _health(health), _level(level) 
	{
		std::cout << "Character " << _name << " created:" << std::endl;
		std::cout << "Health: " << _health << std::endl;
		std::cout << "Level: " << _level << std::endl;
	}

	Character(const std::string& name) : _name(name)
	{
		_health = 100;
		_level = 1;

		std::cout << "Character " << _name << " created:" << std::endl;
		std::cout << "Health: " << _health << std::endl;
		std::cout << "Level: " << _level << std::endl;
	}

	/*
	* Character(const std::string& name, int health = 100, int level = 1) : _name(name), _health(health), _level(level) { ... }
	*/

	~Character()
	{
		std::cout << "Character " << _name << " destroyed." << std::endl;
	}
};

int main()
{
	Character warrior("Warrior");
	Character magician("Magician", 80, 1);
	return 0;
}