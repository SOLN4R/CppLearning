/*
 *	Stack (LIFO: Last In, First Out)
 */

#include <iostream>

template<typename T>
class Stack
{
private:
	T* _data;
	int _top_index;
	int _capacity;

public:
	Stack(int capacity) : _capacity(capacity), _top_index(-1)
	{
		_data = new T[_capacity];
		std::cout << "[Core] A stack with a capacity of " << capacity << " has been created." << std::endl;
	}

	~Stack()
	{
		delete[] _data;
		_data = nullptr;
		std::cout << "[Core] The stack has shut down and cleared the memory." << std::endl;
	}

	bool isFull() const
	{
		return _top_index == _capacity - 1;
	}

	bool isEmpty() const
	{
		return _top_index == -1;
	}

	void Push(const T& value)
	{
		if (isFull()) {
			std::cout << "[Error] Stack overflow." << std::endl;
			return;
		}
		_data[++_top_index] = value;
		std::cout << "[Info] Added element: " << value << std::endl;
	}

	void Pop()
	{
		if (isEmpty()) {
			std::cout << "[Error] Stack is empty." << std::endl;
			return;
		}
		std::cout << "[Info] Element deleted: " << _data[_top_index] << std::endl;
		_top_index--;
	}

	T Top() const
	{
		if (isEmpty()) throw std::out_of_range("[Error] Stack is empty.");
		return _data[_top_index];
	}

	void Clear()
	{
		_top_index = -1;
		std::cout << "[Info] Stack has been cleared." << std::endl;
	}

	void Print() const
	{
		if (isEmpty())
		{
			std::cout << "[Info] Stack is empty." << std::endl;
			return;
		}
		std::cout << "Stack elements:";
		for (int i = 0; i <= _top_index; i++)
		{
			std::cout << " " << _data[i];
		}
		std::cout << std::endl;
	}
};

int main()
{
	Stack<int> numbers(5);
	try {
		std::cout << "Top element: " << numbers.Top() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	numbers.Push(1);
	numbers.Push(9);
	numbers.Push(18);
	numbers.Push(27);
	numbers.Print();
	numbers.Pop();
	numbers.Pop();
	numbers.Print();
	std::cout << "Top element: " << numbers.Top() << std::endl;

	std::cout << std::endl;

	Stack<std::string> spells(5);
	spells.Push("Tornado");
	spells.Push("Cold Snap");
	spells.Push("Sun Strike");
	spells.Push("Chaos Meteor");
	spells.Push("Deafening Blast");
	spells.Print();
	spells.Clear();
	spells.Print();
	return 0;
}	