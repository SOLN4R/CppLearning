/*
 *	Basics and working with memory
 */

#include <iostream>

void DynamicArray(const int);
void TwoDimensionalDynamicArray(const int, const int);

void SwapValue(int&, int&);

int main()
{
	std::cout << "Dynamic array:" << std::endl;
	int size{ 0 };
	std::cout << "Enter the size of the array: ";
	std::cin >> size;
	DynamicArray(size);
	
	std::cout << "\n" << std::endl;

	std::cout << "Two-dimensional dynamic array:" << std::endl;
	int rows, columns;
	std::cout << "Enter the number of rows and columns (a b): ";
	std::cin >> rows >> columns;
	TwoDimensionalDynamicArray(rows, columns);

	std::cout << "\n" << std::endl;

	std::cout << "Swap elements:" << std::endl;
	int a{ 10 }, b{ 20 };
	std::cout << "Before the exchange: a = " << a << ", b = " << b << std::endl;
	SwapValue(a, b);
	std::cout << "After the exchange: a = " << a << ", b = " << b << std::endl;
	return 0;
}

void DynamicArray(const int size)
{
	int* array = new int[size];
	std::cout << "Array:";
	for (int i = 0; i < size; i++)
	{
		array[i] = i + 1;
		std::cout << " " << array[i];
	}
	delete[] array;
	array = nullptr;
}

void TwoDimensionalDynamicArray(const int rows, const int columns)
{
	int value = 1;
	int** array = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[columns];
	}

	std::cout << "Array:" << std::endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = value++;
			std::cout << array[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}

void SwapValue(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;

	/*
	a = a + b;
	b = a - b;
	a = a - b;
	*/
}