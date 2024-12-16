/*
 *	Objective:
 *	Master the basics of inheritance and virtual methods to create a class hierarchy.
 */

#include <iostream>

class Shape
{
protected:
	std::string name;
public:
	Shape(const std::string& shape_name) : name(shape_name) {}
	
	virtual double GetArea() const = 0;

	virtual void PrintInfo() const
	{
		std::cout << "Shape: " << name << std::endl;
	}
};

class Rectangle : public Shape
{
private:
	double width;
	double height;
public:
	Rectangle(const std::string& shape_name, double w, double h) :
		Shape(shape_name), width(w), height(h) { }

	double GetArea() const override 
	{
		return width * height;
	}
	void PrintInfo() const override
	{
		Shape::PrintInfo();
		std::cout << "Area: " << GetArea() << std::endl;
	}
};

class Circle : public Shape
{
private:
	double radius;
public:
	Circle(const std::string& shape_name, double r) :
		Shape(shape_name), radius(r) { }

	double GetArea() const override
	{
		return 3.14 * (radius * radius);
	}
	void PrintInfo() const override
	{
		Shape::PrintInfo();
		std::cout << "Area: " << GetArea() << std::endl;
	}
};

int main()
{
	Shape* shapes[] = {
		new Rectangle("Rectangle", 6, 9),
		new Circle("Circle", 3)
	};

	for (Shape* shape : shapes)
	{
		shape->PrintInfo();
		std::cout << std::endl;
		delete shape;
	}


	return 0;
}