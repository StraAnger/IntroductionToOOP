#include <iostream>

//#define STRUCT_PINT

//Point G; //Global object
int g; //Gloval variable - very bad! DEPRICATED ( осуждаетс€, не одобр€етс€)

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
	//в public сначала пишем гет-сет ( реализуем то есть инкапсул€цию
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

	Point(const Point& other) {

		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyConstructor" << this << std::endl;

	}



	//Destructor

	~Point() {
		std::cout << "Destructor:\t" << this << std::endl;
	
	}

	//   Operators

	void operator = (const Point& other) {

		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyAssignment:\t" << this << std::endl;
	}

    //Methods

	void print() const {

		std::cout << "X= " << x << "\tY= " << y << std::endl;
	}

};



int main() {

#ifdef STRUCT_POINT
	//type name; объ€вление переменной ј типа структуры/класса Point
	//или объ€вление объекта типа Point ( структуры Point), или же создание экземпл€ра ј структуры Point 
	Point A;
	A.x = 2;
	A.y = 3;

	std::cout << A.x<<tab<<A.y<<std::endl;

	Point* pA = &A; //объ€вл€ем указатель на Point 'pA', и инициализируем его адресом объекта 'A'

	std::cout << pA->x << tab << pA->y << std::endl;
#endif //STRUCT_POINT

	Point A; //default constructor
	A.print();

	Point B(4, 5);
	B.print();

	//Point C(5);
	Point C = 5; //можно и так если конструктор с 1 параметром есть
	C.print();

	Point D(5);
	D.print();

	/*
	for (int i = 0; i < 10; ++i) {
		std::cout << i << std::endl;
	}
	*/
	//std::cout << i << std::endl;

	Point E = D; //CopyConstructor
	E.print();

	Point F(B); //CopyConstructor
	F.print();

	Point G;
	G = F; //CopyAssignment (operator =)
	G.print();


	return 0;
}