#include <iostream>


class Point {

	double x;
	double y;
public:
	//в public сначала пишем гет-сет ( реализуем то есть инкапсуляцию )
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

	Point& operator = (const Point& other) {

		this->x = other.x;
		this -> y = other.y;
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

	double distance(const Point& other) const {
		
		//other- другой - просто имя переменной для удобства

		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance* x_distance+ y_distance* y_distance);

		return distance;

	}

};


double distance(const Point& A,const Point& B); 

Point& operator + (const Point& left, const Point& right) {

	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

int main() {
/*
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
	*/
	/*
	int a, b, c;
	a = b = c = 0;
	std::cout << a << "\t" << b << "\t" << c << std::endl;

	Point A, B, C;
	std::cout << "\n--------------------------------------------" << std::endl;
	A=B=C= Point(2, 3);
	//Point(2,3); - явно вызываем конструктор, который создаёт временный безымянный объект.
	std::cout << "\n--------------------------------------------" << std::endl;
	A.print();
	B.print();
	C.print();
	*/
	int a = 2;
	int b = 3;
	int c = a + b;


	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.print();
	C++;
	++C;

	return 0;
}

double distance(const Point& A, const Point& B) {

	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);

	return 0;
}

