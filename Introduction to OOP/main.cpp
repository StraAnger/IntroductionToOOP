#include <iostream>

#define tab "\t"

struct Point {

	double x;
	double y;

};

int main() {
	//type name; ���������� ���������� � ���� ���������/������ Point
	//��� ���������� ������� ���� Point ( ��������� Point), ��� �� �������� ���������� � ��������� Point 
	Point A;
	A.x = 2;
	A.y = 3;

	std::cout << A.x<<tab<<A.y<<std::endl;

	Point* pA = &A; //��������� ��������� �� Point 'pA', � �������������� ��� ������� ������� 'A'

	std::cout << pA->x << tab << pA->y << std::endl;

	return 0;
}