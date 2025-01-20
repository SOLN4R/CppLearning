/*
 *	Vector
 */

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	std::cout << "Vector size: " << vec.size() << std::endl;
	std::cout << "Vecto contains:";
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << " " << *it;
	}

	std::cout << std::endl;

	vec.pop_back();
	
	try {
		std::cout << vec.at(2) << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}