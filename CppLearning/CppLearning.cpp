/*
 *	Objective:
 *	Develop a singly linked list in C++ with the ability to dynamically manage nodes
 *	and perform standard operations such as insertion, deletion, and traversal.
 */

#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node(const int data, Node* next = nullptr) : data(data), next(next) {}
};

class LinkedList
{
private:
	Node* head;

public:
	LinkedList() : head(nullptr) {}
	~LinkedList()
	{
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
	}

	bool IsEmpty() const
	{
		return head == nullptr;
	}

	void InsertFront(const int value) // adds an item to the top of the list
	{
		head = new Node(value, head);
	}

	void InsertBack(int value) // adds an item to the end of the list
	{
		Node* new_node = new Node(value);

		if (IsEmpty()) 
		{
			head = new_node;
			return;
		}

		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new_node;
	}

	void DeleteValue(const int value) // deletes the first node containing the specified value
	{
		if (IsEmpty())
		{
			std::cout << "The list is empty." << std::endl;
			return;
		}

		Node* current = head;
		Node* previous = nullptr;

		while (current != nullptr)
		{
			if (current->data == value)
			{
				if (current == head)
				{
					head = head->next;
					delete current;
					return;
				}
				previous->next = current->next;
				delete current;
				return;
			}
			previous = current;
			current = current->next;
		}

		std::cout << "Value " << value << " not found in the list." << std::endl;
	}

	void PrintList(const std::string& message = "List:") const
	{
		if (IsEmpty())
		{
			std::cout << "The list is empty." << std::endl;
			return;
		}

		std::cout << message << "\t";

		Node* current = head;
		while (current != nullptr)
		{
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
};

int main()
{
	LinkedList list;

	list.PrintList();

	list.InsertFront(1);
	list.InsertFront(2);
	list.InsertFront(3);
	list.PrintList("List after inserting at front:");

	list.InsertBack(4);
	list.InsertBack(5);
	list.InsertBack(2);
	list.PrintList("List after inserting at back:");

	list.DeleteValue(2);
	list.PrintList("List after deleting value 2:");

	list.DeleteValue(2);
	list.PrintList("List after deleting value 2:");

	list.DeleteValue(2);
	return 0;
}