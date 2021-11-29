#include <iostream>


class Fraction {

	double x;
	double y;

public:
	
	//Get&Set

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

	Fraction() {

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

	Point& operator = (const Point& other) {

		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyAssignment:\t" << this << std::endl;
		return *this;
	}

	Point& operator ++ () { //preffix increment

		this->x++;
		this->y++;
		return *this; //Возвращается изменённое значение
	}

	Point& operator ++ (int) { //postfix increment

		Point old = *this; //сохраняем старое значение объекта
		x++;
		y++;
		return old; //возвращаем старое значение ( не изменённое)
	}


	//Destructor

	~Point() {
		std::cout << "Destructor:\t" << this << std::endl;

	}

	//Methods

	void print() const {

		std::cout << "X= " << x << "\tY= " << y << std::endl;
	}

	double devision(const Fraction& other) const {

		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);

		return this->y;

	}

};


Fraction& operator * (const Fraction& left, const Fraction& right) {

	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

int main() {

	Fraction A;	//Default onstructor
	A.print();
	Fraction B = 5;
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print()
	Fraction E = C * D;
	E.print();

	return 0;
}