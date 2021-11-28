#include <iostream>


class Point {

	double x;
	double y;
public:
	//в public сначала пишем гет-сет ( реализуем то есть инкапсул€цию )
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

	double distance(const Point& other) const {
		
		//other- другой - просто им€ переменной дл€ удобства

		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance* x_distance+ y_distance* y_distance);

		return distance;

	}

};


double distance(const Point& A,const Point& B); 


int main() {

	Point A(2,2); 
	A.print();

	Point B(4, 4);
	B.print();
	std::cout << "\n--------------------------------------------" << std::endl;
	std::cout << " Distance from point A to B is: " << A.distance(B) << "\n";
	std::cout << "\n--------------------------------------------" << std::endl;
	std::cout << " Distance from point B to A is: " << B.distance(A) << "\n";
	std::cout << "\n--------------------------------------------" << std::endl;
	std::cout << " Distance between point A and point B is: " << distance(A,B) << "\n";
	std::cout << "\n--------------------------------------------" << std::endl;
	std::cout << " Distance between point B and point A is: " << distance(B, A) << "\n";
	std::cout << "\n--------------------------------------------" << std::endl;

	/*

	int a, b, c;
	a = b = c = 0;
	std::cout << a << "\t" << b << "\t" << c << std::endl;

	Point A, B, C;

	A=B=C= Point(2, 3);
	A.print();
	B.print();
	C.print();
	*/

	return 0;
}

double distance(const Point& A, const Point& B) {

	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);

	return 0;
}

