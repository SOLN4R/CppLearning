/*
 *	Objective:
 *	Learn to manage dynamic memory safely and
 *	efficiently using std::unique_ptr for arrays of objects.
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

	void PrintInfo() const
	{
		std::cout << "Product: " << name << " | Price: " << price << std::endl;
	}

	~Product() {}
};

class ProductManagerSmart
{
private:

	// Product* products;
	std::unique_ptr<Product[]> products;
	int array_size;

public:

	ProductManagerSmart(const int size) : array_size(size)
	{
		if (size <= 0) throw std::invalid_argument("Size of the array must be greater than 0!");
		//products = new Product[array_size];
		products = std::make_unique<Product[]>(array_size);
	}

	void AddProduct(int index, const std::string& name, double price)
	{
		if (index < 0 || index >= array_size) throw std::range_error("Going outside the array!");
		products[index] = Product(name, price);
	}

	void PrintAllProducts() const
	{
		std::cout << "Product list:" << std::endl;
		for (int i = 0; i < array_size; i++)
		{
			products[i].PrintInfo();
		}
	}

	~ProductManagerSmart() {
		//delete[] products;
	}

};

int main()
{
	ProductManagerSmart product_list(3);

	try
	{
		product_list.AddProduct(0, "Apple", 1.5);
		product_list.AddProduct(1, "Banana", 0.9);
		product_list.AddProduct(2, "Orange", 1.2);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Invalid argiment: " << e.what() << std::endl;
	}
	catch (const std::range_error& e)
	{
		std::cerr << "Range error: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "An unknown error occurred." << std::endl;
	}

	product_list.PrintAllProducts();

	return 0;
}