/*
	Objective:
	Learn how to create and use functions to solve problems and structure code.
*/

#include <iostream>

int Add(const int a, const int b); // Returns the sum of two numbers
int Subtract(const int a, const int b); // Returns the difference between two numbers.
bool IsEven(const int number); // Returns true if the number is even, and false otherwise.

int main()
{
	int first_number{0}, second_number{0};

	std::cout << "Enter the first number: ";
	std::cin >> first_number;

	std::cout << "Enter the second number: ";
	std::cin >> second_number;

	std::cout << std::endl;

	std::cout << "Addition: " << Add(first_number, second_number) << std::endl;
	std::cout << "Subtract: " << Subtract(first_number, second_number) << std::endl;

	std::cout << "The number " << first_number << " is ";
	if(IsEven(first_number))
	{
		std::cout << "even." << std::endl;
	}
	else
	{
		std::cout << "odd." << std::endl;
	}

	return 0;
}

int Add(const int a, const int b)
{
	return a + b;
}

int Subtract(const int a, const int b)
{
	return a - b;
}

bool IsEven(const int number)
{
	return number % 2 == 0;
}
