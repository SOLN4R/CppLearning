/*
 *	Objective:
 *	Practice inheritance and polymorphism by creating a base class 
 *	and implementing derived classes with overridden methods.
 */

#include <iostream>

class Animal
{
protected:
	std::string name;
public:
	Animal(const std::string& a_name) : name(a_name) {}

	virtual void MakeSound() const = 0;

	virtual void PrintInfo() const
	{
		std::cout << "Animal: " << name << std::endl;
	}
};

class Dog : public Animal
{
public:
	Dog(const std::string& d_name) : Animal(d_name) {}

	void MakeSound() const override
	{
		std::cout << "Woof!" << std::endl;
	}
};

class Cat : public Animal
{
public:
	Cat(const std::string& c_name) : Animal(c_name) {}
	void MakeSound() const override
	{
		std::cout << "Meow!" << std::endl;
	}
};

int main()
{
	Animal* animals[] = {
		new Dog("Rex"),
		new Cat("Murzik")
	};

	for (Animal* animal : animals)
	{
		animal->PrintInfo();
		animal->MakeSound();
		std::cout << std::endl;
		delete animal;
	}
	return 0;
}