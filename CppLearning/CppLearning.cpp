/*
 *	Objective:
 *	Learn how to work with multidimensional arrays and
 *	apply basic algorithms for processing them.
 */

#include <iostream>

const int ROWS{ 3 }, COLUMNS{ 3 };

/*
 * Calculates the sum of all elements in a 2D array.
 *
 * @param array Pointer to a 2D array with fixed columns (COLUMNS).
 * @return The sum of all elements in the array as an integer.
 */
int Addition(const int (*array)[COLUMNS]);

/*
 * Finds the maximum value in a 2D array and its position.
 *
 * @param array Pointer to a 2D array with fixed columns (COLUMNS).
 * @param row Reference to an integer where the row index of the maximum value will be stored.
 * @param column Reference to an integer where the column index of the maximum value will be stored.
 * @return The maximum value in the array as an integer.
 */
int FindMax(const int (*array)[COLUMNS], int& row, int& column);

/*
 * Calculates the average value of all elements in a 2D array.
 *
 * @param array Pointer to a 2D array with fixed columns (COLUMNS).
 * @return The average value of the elements as a double.
 */
double Average(const int (*array)[COLUMNS]);


void main()
{
	srand(static_cast<unsigned int>(time(0)));

	int matrix[ROWS][COLUMNS] = {};

	std::cout << "Matrix:" << std::endl;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			matrix[i][j] = rand() % 50 + 1;
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Sum of elements: " << Addition(matrix) << std::endl;

	int max_value_row{}, max_value_column{};
	std::cout << "Maximum value: " << FindMax(matrix, max_value_row, max_value_column)
		<< " at position (" << max_value_row << ", " << max_value_column << ")" << std::endl;

	std::cout << "Average value: " << Average(matrix) << std::endl;
}

int Addition(const int (*array)[COLUMNS])
{
	int result{ 0 };
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			result += array[i][j];
		}
	}
	return result;
}

int FindMax(const int (*array)[COLUMNS], int& row, int& column)
{
	int max_value = array[0][0];

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (max_value < array[i][j])
			{
				max_value = array[i][j];
				row = i;
				column = j;
			}
		}
	}

	return max_value;
}

double Average(const int (*array)[COLUMNS])
{
	double result{};

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			result += array[i][j];
		}
	}

	return result / (ROWS * COLUMNS);
}