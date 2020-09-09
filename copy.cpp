#include <iostream>

class Point
{
private:
	int x, y;
	int *z = new int;

public:
	Point(int x1, int y1, int z1)
	{
		x = x1;
		y = y1;
		*z = z1;
	}

	// Copy constructor
	Point(const Point &p2)
	{
		x = p2.x;
		y = p2.y;
		*z = *p2.z;
	}

	int getX() { return x; }
	int getY() { return y; }
	int getZ() { return *z; }
};

int main()
{
	Point p1(10, 15, 20); // Normal constructor is called here
	Point p2 = p1;		  // Copy constructor is called here


	std::cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY() << ", p1.z = " << p1.getZ();
	std::cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY() << ", p2.z = " << p2.getZ();

	return 0;
}
