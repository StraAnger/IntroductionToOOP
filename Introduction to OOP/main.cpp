#include <iostream>

#define tab "\t"

struct Point {

	double x;
	double y;

};

int main() {
	//type name; объ€вление переменной ј типа структуры/класса Point
	//или объ€вление объекта типа Point ( структуры Point), или же создание экземпл€ра ј структуры Point 
	Point A;
	A.x = 2;
	A.y = 3;

	std::cout << A.x<<tab<<A.y<<std::endl;

	Point* pA = &A; //объ€вл€ем указатель на Point 'pA', и инициализируем его адресом объекта 'A'

	std::cout << pA->x << tab << pA->y << std::endl;

	return 0;
}