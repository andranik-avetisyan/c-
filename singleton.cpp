#include <iostream>

class Singleton
{
	private:
		Singleton() {};
		Singleton(const Singleton&);
		Singleton operator=(Singleton&);
		static Singleton* instance;
	public:
		static Singleton* getInstance();
};

Singleton* Singleton::instance = 0;
Singleton* Singleton::getInstance()
{
	if (instance == 0)
	{
		return instance = new Singleton;
	}
	return instance;
}

int main ()
{
	Singleton* a = Singleton::getInstance();
	Singleton* b = Singleton::getInstance();
	std::cout << a << std::endl << b << std::endl;
}
