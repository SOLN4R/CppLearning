/*
 *	 Basics of OOP: polymorphism
 */

#include <iostream>

const int MAX_HEALTH = 100;
const int INITIAL_LEVEL = 1;
const int INITIAL_MANA = 20;
const int MANA_COST_SPELL = 10;

class Character
{
protected:
	std::string name;
	int health;
	int level;

public:
	Character(const std::string& name, int health = MAX_HEALTH, int level = INITIAL_LEVEL) : name(name), health(health), level(level) {}
	virtual ~Character()
	{
		std::cout << "Character " << name << " destroyed." << std::endl;
	}
	virtual void DisplayStatus() const {}
};

class Warrior : public Character
{
private:
	std::string _weapon;
public:
	Warrior(const std::string& name, const std::string& weapon) : Character(name), _weapon(weapon)
	{
		std::cout << "Warrior created." << std::endl;
	}
	~Warrior()
	{
		std::cout << "Warrior " << name << " destroyed." << std::endl;
	}
	
	void DisplayStatus() const override
	{
		std::cout << "Warrior info:" << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Health: " << health << std::endl;
		std::cout << "Level: " << level << std::endl;
		std::cout << "Weapon: " << _weapon << std::endl;
	}
};

class Magician : public Character
{
private:
	int _mana;
public:
	Magician(const std::string& name, int mana = INITIAL_MANA) : Character(name), _mana(mana)
	{
		std::cout << "Magician created." << std::endl;
	}
	~Magician()
	{
		std::cout << "Magician " << name << " destroyed." << std::endl;
	}

	void DisplayStatus() const override
	{
		std::cout << "Magician info:" << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Health: " << health << std::endl;
		std::cout << "Level: " << level << std::endl;
		std::cout << "Mana: " << _mana << std::endl;
	}
};

int main()
{
	int const CHARACTERS_COUNT = 2;
	Character* characters[CHARACTERS_COUNT]{};

	characters[0] = new Warrior("Troll", "Axe");
	characters[1] = new Magician("Invoker");

	for (int i = 0; i < CHARACTERS_COUNT; i++)
	{
		characters[i]->DisplayStatus();
		delete characters[i];
	}
	return 0;
}