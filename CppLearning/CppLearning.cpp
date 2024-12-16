/*
 *	Objective:
 *	Learn how to create classes, work with objects,
 *	and implement basic OOP concepts: encapsulation, 
 *	constructors and methods.
 */

#include <iostream>

class DynamicArray {
private:
	int* _array;
	int _size;
public:
	DynamicArray() : _array(nullptr), _size(0) {}
	DynamicArray(int size) : _array(new int[size]{}), _size(size) {}
	~DynamicArray() {
		delete[] _array;
		_array = nullptr;
	}
	// Fills the array with random numbers in the range[min, max]
	void FillRandom(int min, int max)
	{
		for (int i = 0; i < _size; i++)
		{
			_array[i] = rand() % (max - min + 1) + min;
		}
	}
	// Outputs an array to the console
	void Print(std::string message) const
	{
		std::cout << message << ": ";
		for (int i = 0; i < _size; i++)
		{
			std::cout << _array[i] << " ";
		}
		std::cout << std::endl;
	}
	// Sorts the array in ascending order (bubble sort)
	void BubbleSort()
	{
		for (int i = 0; i < _size - 1; i++)
		{
			bool is_sorted = true;
			for (int j = 0; j < _size - i - 1; j++)
			{
				if (_array[j] > _array[j + 1])
				{
					std::swap(_array[j], _array[j + 1]);
					is_sorted = false;
				}
			}
			if (is_sorted) break;
		}
	}
	// Returns the sum of all the elements of the array
	int Sum() const
	{
		int result{ 0 };
		for (int i = 0; i < _size; i++)
		{
			result += _array[i];
		}
		return result;
	}
	// Returns the minimum value of the array
	int GetMin() const
	{
		int min{ _array[0] };
		for (int i = 0; i < _size; i++)
		{
			if (min > _array[i]) min = _array[i];
		}
		return min;
	}
	// Returns the maximum value of the array
	int GetMax() const
	{
		int max{ _array[0] };
		for (int i = 0; i < _size; i++)
		{
			if (max < _array[i]) max = _array[i];
		}
		return max;
	}

};

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	DynamicArray dynamic_array(10);
	dynamic_array.FillRandom(1, 100);
	dynamic_array.Print("Array");
	dynamic_array.BubbleSort();
	dynamic_array.Print("Sorted array");
	std::cout << "Sum of elements: " << dynamic_array.Sum() << std::endl;
	std::cout << "Minimum value: " << dynamic_array.GetMin() << std::endl;
	std::cout << "Maximum value: " << dynamic_array.GetMax() << std::endl;
	return 0;
}