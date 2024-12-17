/*
 *	Objective:
 *	Learn and implement template classes and functions to create generalized,
 *  reusable code that works with different data types.
 */

#include <iostream>
#include <typeinfo>

template <typename T>
class Storage
{
protected:
	T value;
public:
	Storage(T input_value) : value(input_value) {}
	void SetValue(const T& new_value)
	{
		value = new_value;
	}
	T GetValue() const
	{
		return value;
	}
	void PrintValue() const
	{
		std::cout << "Storage <";

		if (typeid(value) == typeid(std::string)) 
			std::cout << "std::string";
		else
			std::cout << typeid(value).name();

		std::cout << ">: " << GetValue() << std::endl;
	}
};

template <typename T>
T GetMax(T a, T b)
{
	return (a > b) ? a : b;
}

int main()
{
	Storage<int> value_int(10);
	value_int.PrintValue();

	Storage<double> value_double(15.5);
	value_double.PrintValue();

	Storage<std::string> value_string("Hello, Templates!");
	value_string.PrintValue();

	std::cout << std::endl;

	auto a_int = Storage<int>(0);
	auto b_int = Storage<int>(0);

	a_int.SetValue(10);
	b_int.SetValue(20);
	std::cout << "Max of " << a_int.GetValue() << " and " << b_int.GetValue() << ": " << GetMax(a_int.GetValue(), b_int.GetValue()) << std::endl;

	Storage<double> a_double(3.5);
	Storage<double> b_double(2.1);
	std::cout << "Max of " << a_double.GetValue() << " and " << b_double.GetValue() << ": " << GetMax(a_double.GetValue(), b_double.GetValue()) << std::endl;

	Storage<std::string> a_string("apple");
	Storage<std::string> b_string("orange");
	std::cout << "Max of " << a_string.GetValue() << " and " << b_string.GetValue() << ": " << GetMax(a_string.GetValue(), b_string.GetValue()) << std::endl;

	return 0;
}