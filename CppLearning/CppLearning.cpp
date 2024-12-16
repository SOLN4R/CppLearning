/*
	Objective:
	Get acquainted with basic arithmetic operations in C++ and learn how to read data from the user.
*/

#include <iostream>

int main()
{
	int first_number{ 0 }, second_number{ 0 };

	std::cout << "Enter the first integer: ";
	std::cin >> first_number;

	std::cout << "Enter the second integer: ";
	std::cin >> second_number;

	std::cout << std::endl;

	std::cout << "Addition: " << (first_number + second_number) << std::endl;
	std::cout << "Subtraction: " << (first_number - second_number) << std::endl;
	std::cout << "Multiplication: " << (first_number * second_number) << std::endl;
	
	if (second_number != 0)
	{
		std::cout << "Division: " << (static_cast<double>(first_number) / second_number) << std::endl;
		std::cout << "The remainder of the division: " << (first_number % second_number) << std::endl;
	}
	else 
	{
		std::cout << "Error: Division and remainder operations are not possible when the second number is zero." << std::endl;
	}

	return 0;
}