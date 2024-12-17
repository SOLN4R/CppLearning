/*
 *	Objective:
 *	Practice using abstract classes, pure virtual methods,
 *  and inheritance to build a flexible and modular program structure.
 */

#include <iostream>

class Device
{
protected:
	std::string name;
public:
	Device(const std::string& device_name) : name(device_name) {}
	virtual void TurnOn() const = 0;
	virtual void TurnOff() const = 0;
	virtual void ShowInfo() const
	{
		std::cout << "Device: " << name << std::endl;
	}
};

class Smartphone : public Device
{
private:
	std::string brand;
	int battery_life;
public:
	Smartphone(const std::string& device_name, const std::string& brand_name, const int battery_life) :
		Device(device_name), brand(brand_name), battery_life(battery_life) { }

	void TurnOn() const override
	{
		std::cout << "Turning on the device..." << std::endl;
	}
	void TurnOff() const override
	{
		std::cout << "Turning off the device..." << std::endl;
	}

	void ShowInfo() const override
	{
		Device::ShowInfo();
		std::cout << "Brand: " << brand << std::endl;
		std::cout << "Battery Life: " << battery_life << " hours" << std::endl;
	}
};

class Laptop : public Device
{
private:
	std::string model;
	int ram;
public:
	Laptop(const std::string& device_name, const std::string& model_name, const int ram_count) :
		Device(device_name), model(model_name), ram(ram_count) { }
	void TurnOn() const override
	{
		std::cout << "Turning on the device..." << std::endl;
	}
	void TurnOff() const override
	{
		std::cout << "Turning off the device..." << std::endl;
	}
	void ShowInfo() const override
	{
		Device::ShowInfo();
		std::cout << "Model: " << model << std::endl;
		std::cout << "RAM: " << ram << " GB" << std::endl;
	}
};

int main()
{
	Device* devices[] = {
		new Smartphone("Smartphone", "Apple", 10),
		new Laptop("Laptop", "Dell XPS 15", 16)
	};

	for (Device* device : devices)
	{
		device->TurnOn();
		device->ShowInfo();
		device->TurnOff();
		delete device;
		std::cout << std::endl;
	}
	return 0;
}