#include <iostream>
#include <string>

class Car
{
	public:
		Car() {};
		std::string color;
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
class Factory 
{
	public:
		virtual Car* getCar() = 0;
};
class RedFactory : public Factory
{
	public:
		virtual Car* getCar()
		{
			return new RedCar();
		}
};
class BlueFactory
{
	public:
		virtual Car* getCar()
		{
			return new BlueCar();
		}
};

int main()
{
	RedFactory* redfactory = new RedFactory;
	Car* redcar = redfarory->getCar();
	std::cout << redcar->color << std::endl;
	BlueFactory* bluefactory = new BlueFactory;
	Car* bluecar = bluefactory->getCar();
	std::cout << bluecar->color << std::endl;
}

