#include <iostream>

//#define STRUCT_PINT

#define tab "\t"

/*

struct Point {
	double x;
	double y;
};

*/

class Point {

	double x;
	double y;
public:

	double get_x() const {
		return x;
	}

	double get_y() const {
		return y;
	}

	void set_x(double x) {
		this->x = x;
	}

	void set_y(double y) {
		this->y = y;
	}

};



int main() {

#ifdef STRUCT_POINT
	//type name; ���������� ���������� � ���� ���������/������ Point
	//��� ���������� ������� ���� Point ( ��������� Point), ��� �� �������� ���������� � ��������� Point 
	Point A;
	A.x = 2;
	A.y = 3;

	std::cout << A.x<<tab<<A.y<<std::endl;

	Point* pA = &A; //��������� ��������� �� Point 'pA', � �������������� ��� ������� ������� 'A'

	std::cout << pA->x << tab << pA->y << std::endl;
#endif //STRUCT_POINT

	Point A;
	A.set_x(2);
	A.set_y(3);


	std::cout << A.get_x() << tab << A.get_y() << std::endl;


	return 0;
}