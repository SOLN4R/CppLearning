/*
	Objective:
	Learn how to use conditional constructions (if, else if, else)
	and loops (for, while, do-while) to control program logic.
*/

#include <iostream>

int main()
{
	int number{ 0 };

	// Determining the parity of a number
	std::cout << "Determining the parity of a number" << std::endl;
	std::cout << "Enter an integer: ";
	std::cin >> number;
	if (number > 0)
	{
		std::cout << "The number is positive." << std::endl;
	}
	else if (number < 0)
	{
		std::cout << "The number is negative." << std::endl;
	}
	else
	{
		std::cout << "The number is zero." << std::endl;
	}

	std::cout << std::endl;

	// Output of numbers from 1 to N
	std::cout << "Output of numbers from 1 to N" << std::endl;
	std::cout << "Enter an integer for N: ";
	std::cin >> number;
	std::cout << "Numbers from 1 to N:";
	for (int i = 1; i <= number; i++)
	{
		std::cout << " " << i;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	// Output of even numbers from 1 to N
	std::cout << "Output of even numbers from 1 to N" << std::endl;
	std::cout << "Enter an integer for N: ";
	std::cin >> number;
	std::cout << "Even numbers from 1 to M:";
	int even_candidate{ 0 };
	while (++even_candidate <= number)
	{
		if (even_candidate % 2 == 0)
		{
			std::cout << " " << even_candidate;
		}
	}

	std::cout << std::endl;
	std::cout << std::endl;

	// Entering a positive integer
	std::cout << "Entering a positive integer" << std::endl;
	do
	{
		std::cout << "Enter a positive integer: ";
		std::cin >> number;
	} while (number <= 0);
	std::cout << "Thank you! The positive number is " << number << "." << std::endl;

	return 0;
}