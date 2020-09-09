#include <iostream>

class Dollars
{
	private:
		int mydollars;

	public:
		Dollars(int dollars)
		{
			mydollars = dollars;
		}
		Dollars operator+(int value);
		int getDollars()
		{
			return mydollars;
		}
};

Dollars Dollars::operator+(int value)
{
	return Dollars(mydollars + value);
}

int main ()
{
	Dollars dollars1(12);
	Dollars dollars2 = dollars1 + 3;
	std::cout << "I have " << dollars2.getDollars() << " dollars.\n";

	return 0;
}
