/*
 *	Objective:
 *	Implement two fundamental data structures, Stack and Queue,
 *	using dynamic arrays managed by std::unique_ptr.
 */

#include <iostream>

class Stack // LIFO (Last In, First Out)
{
private:

	std::unique_ptr<int[]> data;
	int capacity; // the maximum stack capacity
	int top; // is the index of the top element of the stack

public:

	Stack(const int size) : capacity(size), top(-1)
	{
		data = std::make_unique<int[]>(capacity);
	}
	bool IsEmpty() const
	{
		return top < 0;
	}
	bool IsFull() const
	{
		return top + 1 == capacity;
	}
	void Push(const int value)
	{
		
		if (IsFull()) throw std::overflow_error("The stack is full.");
		data[++top] = value;
	}
	int Pop()
	{
		if (IsEmpty()) throw std::underflow_error("The stack is empty.");
		return data[top--];
	}
	
	void Print(const std::string& message = "Stack elements:\t\t") const
	{
		if (IsEmpty()) throw std::underflow_error("The stack is empty.");
		std::cout << message;
		for (int i = 0; i <= top; i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};

class Queue // FIFO (First In, First Out)
{
private:

	std::unique_ptr<int[]> data;
	int capacity;
	int front;		// is the index of the first element of the queue
	int rear;		// is the index of the last element of the queue.
	int size;		// the current queue size

public:
	Queue(const int capacity) : capacity(capacity), front(0), rear(0), size(0)
	{
		data = std::make_unique<int[]>(capacity);
	}

	bool IsFull() const
	{
		return size == capacity;
	}
	bool IsEmpty() const
	{
		return !size;
	}
	void Enqueue(int value)
	{
		if (IsFull()) throw std::overflow_error("The queue is full.");
		data[rear] = value;
		rear = (rear + 1) % capacity;
		size++;
	}
	int Dequeue()
	{
		if (IsEmpty()) throw std::overflow_error("The queue is empty.");
		int value = data[front];
		front = (front + 1) % capacity;
		size--;
		return value;
	}

	void Print(const std::string& message = "Queue elements:\t\t") const
	{
		if (IsEmpty()) throw std::underflow_error("The queue is empty.");
		std::cout << message;
		for (int i = 0; i < size; i++)
		{
			int index = (front + i) % capacity;
			std::cout << data[index] << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	Stack stack(5);

	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);

	stack.Print();

	stack.Pop();
	stack.Print("Stack after pop:\t");

	stack.Pop();
	stack.Print("Stack after pop:\t");
	
	stack.Push(9);
	stack.Print("Stack after push (9):\t");

	std::cout << std::endl;

	Queue queue(5);

	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);
	queue.Enqueue(5);

	queue.Print();

	queue.Dequeue();
	queue.Print("Queue after Dequeue:\t");

	queue.Dequeue();
	queue.Print("Queue after Dequeue:\t");

	queue.Enqueue(9);
	queue.Print("Queue after Enqueue:\t");

	return 0;
}