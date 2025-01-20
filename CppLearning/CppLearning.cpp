/*
 *	 sort, find, for_each
 */

#include <iostream>
#include <vector>
#include <algorithm>
#

void PrintNumbers(std::vector<int>&);
void SortingNumbers(std::vector<int>&, bool = false);
void FindNumber(std::vector<int>&, int);

int main()
{
	std::vector<int> numbers{ 0, 4, 2, 6, 1, 5, 8, 7, 9, 3 };
	PrintNumbers(numbers);
	
	SortingNumbers(numbers);
	PrintNumbers(numbers);

	SortingNumbers(numbers, true);
	PrintNumbers(numbers);

	FindNumber(numbers, 5);
	FindNumber(numbers, 18);

	return 0;
}

void PrintNumbers(std::vector<int>& numbers)
{
	std::cout << "\nNumbers (" << numbers.size() << "):";
	std::for_each(numbers.begin(), numbers.end(), [](int number)
		{
			std::cout << " " << number;
		});

	std::cout << std::endl;
}

void SortingNumbers(std::vector<int>& numbers, bool reverse)
{
	if (reverse)
	{
		std::cout << "\nReverse sorting..." << std::endl;
		std::sort(numbers.begin(), numbers.end(), std::greater<int>());
		return;
	}
	std::cout << "\nSorting..." << std::endl;
	std::sort(begin(numbers), end(numbers));
}

void FindNumber(std::vector<int>& numbers, int find_number)
{
	auto it = std::find(numbers.begin(), numbers.end(), find_number);
	std::cout << "\nFinding " << find_number << "..." << std::endl;
	if (it != numbers.end())
	{
		std::cout << "\nFound: " << *it << std::endl;
		return;
	}
	std::cout << "\nThe number " << find_number << " was not found" << std::endl;
}