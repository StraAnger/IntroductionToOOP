#include <iostream>

//#define STRUCT_PINT

//Point G; //Global object
int g; //Gloval variable - very bad! DEPRICATED ( ����������, �� ����������)

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
	//� public ������� ����� ���-��� ( ��������� �� ���� ������������
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

	//Constructor

	Point() {

		x = y = 0;
		std::cout << "defaultConstructor:\t" << this << std::endl;

	}

	//Constructor

	Point(double x) {

		this->x = x;
		this->y = 0;
		std::cout << "1arg Constructor:\t" << this << std::endl;

	}

	//Constructor

	Point(double x, double y) {

		this->x = x;
		this->y = y;
		std::cout << "Constructor:\t" << this << std::endl;

	}

	//Destructor

	~Point() {
		std::cout << "Destructor:\t" << this << std::endl;
	
	}

    //Methods

	void print() const {

		std::cout << "X= " << x << "\tY= " << y << std::endl;
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

	Point A; //default constructor
//	A.set_x(2);
//	A.set_y(3);


	//std::cout << A.get_x() << tab << A.get_y() << std::endl;

	A.print();

	Point B(4, 5);
	B.print();

	//Point C(5);
	Point C = 5; //����� � ��� ���� ����������� � 1 ���������� ����
	C.print();

	/*
	for (int i = 0; i < 10; ++i) {
		std::cout << i << std::endl;
	}
	*/
	//std::cout << i << std::endl;

	return 0;
}