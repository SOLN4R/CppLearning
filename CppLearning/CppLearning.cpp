/*
 *	Objective:
 *	Implement the Insertion Sort algorithm to sort a dynamic array of objects based
 *	on their price. The dynamic array is managed using std::unique_ptr for safe memory management.
 */

#include <iostream>

class Product
{
private:

	std::string name;
	double price;

public:

	Product(const std::string product_name = "Unknow", const double product_price = 0.0) :
		name(product_name), price(product_price) {
	}

	double GetPrice() const
	{
		return price;
	}

	void PrintInfo() const
	{
		std::cout << "Product: " << name << " | Price: " << price << std::endl;
	}
};

class ProductManagerSmart
{
private:

	std::unique_ptr<Product[]> products;
	int array_size;

public:

	ProductManagerSmart(const int size) : array_size(size)
	{
		if (size <= 0) throw std::invalid_argument("Size of the array must be greater than 0!");
		products = std::make_unique<Product[]>(array_size);
	}

	void AddProduct(int index, const std::string& name, double price)
	{
		if (products == nullptr) throw std::logic_error("Products array is not initialized.");
		if (index < 0 || index >= array_size) throw std::range_error("Going outside the array!");
		products[index] = Product(name, price);
	}

	void PrintAllProducts(bool ascending = true) const
	{
		std::cout << "Product list (sorted in " << (ascending ? "ascending" : "descending") << " order):" << std::endl;
		for (int i = 0; i < array_size; i++)
		{
			products[i].PrintInfo();
		}
	}
	
	void InsertionSortByPrice(bool ascending = true)
	{
		if (!products) throw std::logic_error("The array is empty");
		for (int i = 1; i < array_size; i++)
		{
			Product key = products[i];
			int j = i - 1;

			while (j >= 0 && 
				(ascending ? products[j].GetPrice() > key.GetPrice()
				: products[j].GetPrice() < key.GetPrice()))
			{
				products[j + 1] = products[j];
				j--;
			}
			products[j + 1] = key;
		}
	}
};

int main()
{
	ProductManagerSmart product_list(5);

	try
	{
		product_list.AddProduct(0, "Pineapple", 2.5);
		product_list.AddProduct(1, "Apple", 1.5);
		product_list.AddProduct(2, "Banana", 0.9);
		product_list.AddProduct(3, "Mango", 3.0);
		product_list.AddProduct(4, "Orange", 1.8);

		product_list.InsertionSortByPrice(true);
		product_list.PrintAllProducts(true);

		std::cout << std::endl;

		product_list.InsertionSortByPrice(false);
		product_list.PrintAllProducts(false);

		
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	}
	catch (const std::range_error& e)
	{
		std::cerr << "Range error: " << e.what() << std::endl;
	}
	catch (const std::logic_error& e)
	{
		std::cerr << "Logic error: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "An unknown error occurred." << std::endl;
	}
	return 0;
}