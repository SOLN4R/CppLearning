/*
 *	Objective:
 *	Strengthen understanding of inheritance and polymorphism by creating
 *	a base class and derived classes with virtual methods.
 */

#include <iostream>

class Vehicle
{
protected:
	std::string name;
	int speed;
public:
	Vehicle(const std::string& vehicle_name, int vehicle_speed) :
		name(vehicle_name), speed(vehicle_speed) { }

	int GetSpeed() const { return speed; }

	virtual void PrintInfo() const
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Speed: " << speed << " km/h" << std::endl;
	}
	virtual double GetTravelTime(double distance) const = 0;
};

class Car : public Vehicle
{
private:
	int fuelEfficiency;
public:
	Car(const std::string& c_name, int c_speed, int c_fuelEfficiency) :
		Vehicle(c_name, c_speed), fuelEfficiency(c_fuelEfficiency) { }

	double GetTravelTime(double distance) const override
	{
		return distance / GetSpeed();
	}
	double CalculateFuel(double distance) const {
		return distance * fuelEfficiency / 100;
	}
	void PrintInfo() const override
	{
		Vehicle::PrintInfo();
		std::cout << "Travel time for 300 km: " << GetTravelTime(300) << " hours" << std::endl;
		std::cout << "Fuel needed: " << CalculateFuel(300) << " liters" << std::endl;
	}
};

class Bicycle : public Vehicle
{
public:
	Bicycle(const std::string& b_name, int b_speed) :
		Vehicle(b_name, b_speed) { }

	double GetTravelTime(double distance) const override
	{
		return distance / GetSpeed();
	}
	void PrintInfo() const override
	{
		Vehicle::PrintInfo();
		std::cout << "Travel time for 300 km: " << GetTravelTime(300) << " hours" << std::endl;
	}
};



int main()
{
	Vehicle* vehicles[] =
	{
		new  Car("Car", 100, 7),
		new Bicycle("Bicycle", 20)
	};

	for (Vehicle* vehicle : vehicles)
	{
		vehicle->PrintInfo();
		std::cout << std::endl;
		delete vehicle;
	}
	return 0;
}