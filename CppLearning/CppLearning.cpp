/*
 *	Objective:
 *	Learn how to work with arrays and pass them to functions,
 *	as well as return results through parameters.
 */

#include <iostream>

int const ARRAY_SIZE = 10;

/*
 * Calculates the average value of the elements in the array.
 *
 * @param arr Pointer to the beginning of the array.
 * @return The average value of the array elements as a double.
 */
double Average(const int* arr);


/*
 * Finds the minimum and maximum values in the array.
 *
 * @param array Reference to an array of fixed size (ARRAY_SIZE).
 * @param min Reference to an integer where the minimum value will be stored.
 * @param max Reference to an integer where the maximum value will be stored.
 */
void FindMinMax(int(&array)[ARRAY_SIZE], int& min, int& max); // 

void main()
{
	int numbers[ARRAY_SIZE];
	int min_value {};
	int max_value {};
	srand(static_cast<unsigned int>(time(0)));

	std::cout << "Array:";
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		numbers[i] = rand() % 100 + 1;
		std::cout << " " << numbers[i];
	}

	std::cout << std::endl;
	std::cout << std::endl;

	FindMinMax(numbers, min_value, max_value);
	std::cout << "Minimum value: " << min_value << std::endl;
	std::cout << "Maximum value: " << max_value << std::endl;
	std::cout << "Average value: " << Average(numbers) << std::endl;
}

double Average(const int* array)
{
	double result{ 0 };
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		result += array[i];
	}
	result /= ARRAY_SIZE;
	return result;
}

void FindMinMax(int(&array)[ARRAY_SIZE], int& min, int& max)
{
	min = array[0];
	max = array[0];

	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		if (min > array[i]) min = array[i];
		if (max < array[i]) max = array[i];
	}
	return;
}