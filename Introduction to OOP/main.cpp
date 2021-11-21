#include <iostream>

#define tab "\t"

struct point {

	double x;
	double y;

};

int main() {
	
	point A;
	A.x = 2;
	A.y = 3;

	std::cout << A.x<<tab<<A.y<<std::endl;

	return 0;
}