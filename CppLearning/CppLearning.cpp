/*
	Objective:
	Learn to work with variables and different data types in C++.
*/

#include <iostream>

int main()
{
	const int var_int = 42;
	const float var_float = 3.14f;
	const double var_double = 2.718;
	const char var_char = 'A';
	const bool var_bool = true;
	const std::string var_string = "Hello World!";

	std::cout << "Value of variable of type int: " << var_int
		<< ", size: " << sizeof(var_int) << " bytes." << std::endl;

	std::cout << "Value of variable of type float: " << var_float
		<< ", size: " << sizeof(var_float) << " bytes." << std::endl;

	std::cout << "Value of variable of type double: " << var_double
		<< ", size: " << sizeof(var_double) << " bytes." << std::endl;

	std::cout << "Value of variable of type char: " << var_char 
		<< ", size: " << sizeof(var_char) << " bytes." << std::endl;

	std::cout << "Value of variable of type bool: " << var_bool 
		<< ", size: " << sizeof(var_bool) << " bytes." << std::endl;

	std::cout << "Value of variable of type string: " << var_string
		<< ", size: " << sizeof(var_string) << " bytes, length: " << var_string.size() << " characters." << std::endl;

	return 0;
}