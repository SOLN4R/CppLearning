/*
 *	Templates: Function and Сlass
 */

#include <iostream>

// Function
template <typename T>
T Add(T a, T b)
{
	return a + b;
}

// Class
template <typename T>
class Box
{
private:
	T item;
public:
	void SetItem(const T& new_item)
	{
		item = new_item;
	}

	T GetItem() const
	{
		return item;
	}
};

int main()
{
	// Function
	std::cout << Add<int>(10, 8) << std::endl;

	// Class
	Box<std::string> box;
	box.SetItem("Chocolate");
	std::cout << "The box contains: " << box.GetItem() << std::endl;
	return 0;
}	