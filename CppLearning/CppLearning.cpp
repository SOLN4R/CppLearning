/*
 *	 Basics of OOP: abstract class and interface
 */

#include <iostream>

// Abstract class
class Character
{
protected:
	std::string name;
public:
	Character(const std::string& name = "NoName") : name(name) {}
	virtual ~Character() {}
	virtual void DisplayStatus() const = 0;

	void SetName(const std::string& new_name)
	{
		name = new_name;
	}
	std::string GetName() const
	{
		return name;
	}

};

// Interface
class Fightable
{
public:
	virtual ~Fightable() {}
	virtual void Attack() const = 0;
};

// Derived class
class Warrior : public Character, public Fightable
{
private:
	std::string _weapon;
public:
	Warrior(const std::string& weapon) : _weapon(weapon)
	{
		std::cout << "Warrior " << name << " created." << std::endl;
	}
	~Warrior()
	{
		std::cout << "Warrior " << name << " destroyed." << std::endl;
	}

	void DisplayStatus() const override
	{
		std::cout << "Warrior info:" << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Weapon: " << _weapon << std::endl;
	}

	void Attack() const override
	{
		std::cout << "Warrior attacks!" << std::endl;
	}
};

class Magician : public Character
{
private:
	int _mana;
public:
	Magician(int mana = 50) : _mana(mana)
	{
		std::cout << "Magician " << name << " created." << std::endl;
	}
	~Magician()
	{
		std::cout << "Magician " << name << " destroyed." << std::endl;
	}
	void DisplayStatus() const override
	{
		std::cout << "Magician info:" << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Mana: " << _mana << std::endl;
	}
};

int main()
{
	int const CHARACTERS_COUNT = 2;
	Character* characters[CHARACTERS_COUNT];
	characters[0] = new Warrior("Axe");
	characters[1] = new Magician();

	characters[0]->SetName("Troll");
	characters[1]->SetName("Invoker");

	Fightable* fightable;
	for(int i = 0; i < CHARACTERS_COUNT; i++)
	{
		std::cout << std::endl;
		characters[i]->DisplayStatus();
		std::cout << std::endl;
		fightable = dynamic_cast<Fightable*>(characters[i]);
		if (fightable) {
			fightable->Attack();
		}
		else {
			std::cout << "Character " << characters[i]->GetName() << " cannot attack." << std::endl;
		}
		delete characters[i];
	}
	return 0;
}