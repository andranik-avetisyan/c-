#include <iostream>
#include <string>

class Car
{
	public:
		Car() {};
		std::string color;
		static Car* getCar(std::string color);
};
class RedCar : public Car
{
	public:
		RedCar()
		{
			color = "red";
		}
};
class BlueCar : public Car 
{
	public:
		BlueCar()
		{
			color = "blue";
		}
};
Car* Car::getCar(std::string color)
{
	if (color == "red")
	{
		return new RedCar();
	}
	else if (color == "blue")
	{
		return new BlueCar();
	}
	else 
	{
		return 0;
	}
};
int main()
{
	Car* redCar = Car::getCar("red");
	std::cout << redCar->color << std::endl;
	Car* blueCar = Car::getCar("blue");
	std::cout << blueCar->color << std::endl;
}
