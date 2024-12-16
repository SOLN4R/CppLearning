/*
 *	Objective:
 *	Learn how to create, fill, and process dynamic arrays
 *	in C++ using memory allocation and deallocation.
 */

#include <iostream>

 /*
  * Sorts the array in ascending order using bubble sort.
  *
  * @param array Pointer to the array to be sorted.
  * @param size The size of the array.
  */
void SortingArray(int* array, int size);

/*
 * Calculates the sum of all elements in the array.
 *
 * @param array Pointer to the array.
 * @param size The size of the array.
 * @return The sum of the elements as an integer.
 */
int Addition(int const* array, int const size);

/*
 * Finds the minimum and maximum values in the array.
 *
 * @param array Pointer to the array.
 * @param size The size of the array.
 * @param min Reference to an integer where the minimum value will be stored.
 * @param max Reference to an integer where the maximum value will be stored.
 */
void FindMinMax(int const* array, int const size, int& min, int& max);

int main()
{
	int array_size{ 0 };
	std::cout << "Enter the size of the array: ";
	std::cin >> array_size;
	std::cout << std::endl;

	int* numbers{ new int[array_size] {} };
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < array_size; i++)
	{
		numbers[i] = rand() % 100 + 1;
	}

	std::cout << "Original array: ";
	for (int i = 0; i < array_size; i++)
	{
		std::cout << numbers[i] << " ";
	}
	
	std::cout << std::endl;

	SortingArray(numbers, array_size);
	std::cout << "Sorted array: ";
	for (int i = 0; i < array_size; i++)
	{
		std::cout << numbers[i] << " ";
	}

	std::cout << std::endl;

	std::cout << "Sum of elements: " << Addition(numbers, array_size) << std::endl;

	int min{}, max{};
	FindMinMax(numbers, array_size, min, max);
	std::cout << "Minimum value: " << min << std::endl;
	std::cout << "Maximum value: " << max << std::endl;

	delete[] numbers;
	numbers = nullptr;

	return 0;
}

void SortingArray(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

int Addition(int const* array, int const size)
{
	int result{ 0 };
	for (int i = 0; i < size; i++)
	{
		result += array[i];
	}
	return result;
}

void FindMinMax(int const* array, int const size, int& min, int& max)
{
	min = array[0];
	max = array[0];

	for (int i = 0; i < size; i++)
	{
		if (min > array[i]) min = array[i];
		if (max < array[i]) max = array[i];
	}
}