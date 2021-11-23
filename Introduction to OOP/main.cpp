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

	double distance(double x, double y) {

		return sqrt(pow((this->x) - x, 2) + pow((this->y) - y, 2));

	}

};


double distance(double x1, double y1, double x2, double y2);


int main() {

	double x1 = double();
	double y1 = double();
	double x2 = double();
	double y2 = double();


	Point A(2,2); 
	A.print();

	Point B(4, 4);
	B.print();

	std::cout << "Enter X and Y coordinates of point 1: "; std::cin >> x1 >> y1;
	std::cout << " Distance from point 1 to A is: " << A.distance(x1, y1) << "\n";
	std::cout << " Distance from point 1 to B is: " << B.distance(x1, y1) << "\n";
	std::cout << "Enter X and Y coordinates of point 2: "; std::cin >> x2 >> y2;
	std::cout << " Distance from point 2 to A is: " << A.distance(x2, y2) << "\n";
	std::cout << " Distance from point 2 to B is: " << B.distance(x2, y2) << "\n";
	std::cout << " Distance between point 1 and point 2 is: " << distance(x1,y1,x2, y2) << "\n";


	return 0;
}

double distance(double x1, double y1, double x2, double y2) {

	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

}