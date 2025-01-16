/*
 *	 Basics of OOP: inheritance
 */

#include <iostream>

const int MIN_HEALTH = 0;
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
	
	void TakeDamage(int amount)
	{
		health = std::max(MIN_HEALTH, health -= amount);

		if (health <= MIN_HEALTH) {
			std::cout << "[Info] " << name << "'s character is destroyed." << std::endl;
		}
		else {
			std::cout << "[Info] " << name << "'s character took damage of " << amount << "." << std::endl;
		}
	}

	void Heal(int amount)
	{
		health = std::min(MAX_HEALTH, health += amount);
		std::cout << "[Info] " << name << "'s character's health has been increased to " << health << "." << std::endl;
	}

	void DisplayStatus()
	{
		std::cout << "Character info:" << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Health: " << health << std::endl;
		std::cout << "Level: " << level << std::endl;
	}
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

	void Attack()
	{
		std::cout << "The " << name << " warrior attacked with " << _weapon << std::endl;
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

	void CastSpell()
	{
		if (_mana - MANA_COST_SPELL < 0) {
			std::cout << "[Info] Not enough mana for spell." << std::endl;
			return;
		}
		_mana -= MANA_COST_SPELL;
		std::cout << "The " << name << " magician cast a spell. Remaining Mana: " << _mana << std::endl;
	}

	void DisplayStatus()
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
	Warrior troll("Troll", "Axe");
	troll.DisplayStatus();
	std::cout << std::endl;

	Magician invoker("Invoker");
	invoker.DisplayStatus();
	std::cout << std::endl;

	troll.Attack();
	invoker.CastSpell();
	invoker.CastSpell();
	invoker.CastSpell();
	return 0;
}