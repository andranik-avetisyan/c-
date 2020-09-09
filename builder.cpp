#include <iostream>
#include <string>

class Engine
{
	public:
		int horsepower;
};
class Body
{
	public:
		std::string shape;
};
class Car
{
	public:
		Engine* engine;
		Body* body;

		void specifications()
		{
			std::cout << "body" << body->shape << std::endl;
			std::cout << "engine" << engine->horsepower << std::endl;
		}
};
class Builder
{
	 public:
		 virtual Engine* getEngine() = 0;
		 virtual Body* getBody() = 0;
};
class Director
{
	Builder* builder;
	public:
		void setBuilder(Builder* newBuilder)
		{
			builder = newBuilder;
		}
        Car* getCar()
		{
	    	Car* car = new Car();
		    car->body = builder->getBody();
    		car->engine = builder->getEngine();
                return car;
        }
};
class JeepBuilder : public Builder
{
	 public:
		 Engine* getEngine()
		 {
			 Engine* engine = new Engine();
			 engine->horsepower = 400;
			 return engine;
		 }
		 Body* getBody()
		 {
			 Body* body = new Body();
			 body->shape = "SUV";
		 }
};
int main()
{
	Car* car;

	Director director;

	JeepBuilder jeepBuilder;

	std::cout << "Jeep" << std::endl;
	director.setBuilder(&jeepBuilder);
	car = director.getCar();
	car->specifications();
	std::cout << std::endl;
	return 0;
}
