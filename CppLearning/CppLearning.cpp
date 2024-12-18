/*
 *	Objective:
 *	Implement a doubly linked list in C++ with the ability to traverse both directions
 *  and perform standard operations (insertion, deletion, and printing).
 */

#include <iostream>

template<typename T>
struct Node
{
	T data;
	Node* next;
	Node* prev;

	Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template<typename T>
class DoublyLinkedList
{
private:
	Node<T>* head; // ptr to the first node of the list
	Node<T>* tail; // ptr to the last node in the list

public:
	DoublyLinkedList() : head(nullptr), tail(nullptr) {}
	~DoublyLinkedList() 
	{
		Node<T>* current = head;

		while (current != nullptr)
		{
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
	}

	bool IsEmpty() const
	{
		return head == nullptr;
	}

	void InsertFront(T value)
	{
		Node<T>* new_node = new Node<T>(value); // next, prev = nullptr

		new_node->next = head;
		
		if (IsEmpty()) tail = new_node;
		else head->prev = new_node;

		head = new_node;
	}

	void InsertBack(T value)
	{
		Node<T>* new_node = new Node<T>(value);
		
		new_node->prev = tail;
		if (IsEmpty()) head = new_node;
		else tail->next = new_node;

		tail = new_node;
	}

	void DeleteValue(T value)
	{
		if (IsEmpty())
		{
			std::cout << "The list is empty." << std::endl;
			return;
		}

		Node<T>* current = head;

		while (current != nullptr)
		{
			if (current->data == value)
			{
				break;
			}
			current = current->next;
		}

		if (current == nullptr)
		{
			std::cout << "Value " << value << " not found in the list." << std::endl;
			return;
		}

		if (current == head)
		{
			head = current->next;
			if (head != nullptr)
			{
				head->prev = nullptr;
			}
			else
			{
				tail = nullptr;
			}
		}
		else if (current == tail)
		{
			tail = current->prev;
			tail->next = nullptr;
		}
		else
		{
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}

		delete current;
		std::cout << "Value " << value << " deleted from the list." << std::endl;
	}


	void PrintList(const std::string& message = "List:", bool reverse = false) const
	{
		if (IsEmpty())
		{
			std::cout << "The list is empty." << std::endl;
			return;
		}

		Node<T>* current = reverse ? tail : head;

		std::cout << message;

		while (current != nullptr)
		{
			std::cout << current->data << " ";

			current = reverse ? current->prev : current->next;
		}

		std::cout << std::endl;
	}
};

int main()
{
	DoublyLinkedList<int> intList;
	
	intList.PrintList();

	intList.InsertFront(3);
	intList.PrintList("List after InsertFront(3):\t");
	intList.InsertFront(2);
	intList.PrintList("List after InsertFront(2):\t");

	std::cout << std::endl;

	intList.InsertBack(4);
	intList.PrintList("List after InsertBack(4):\t");
	intList.InsertBack(5);
	intList.PrintList("List after InsertBack(5):\t");

	std::cout << std::endl;

	intList.PrintList("List (reversed):\t\t", true);
	intList.PrintList("List:\t\t\t\t");

	std::cout << std::endl;

	intList.DeleteValue(3);
	intList.PrintList("List after DeleteValue(3):\t");
	intList.DeleteValue(6);
	return 0;
}