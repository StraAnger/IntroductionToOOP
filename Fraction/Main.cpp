#include <iostream>


class Fraction {

	double x;
	double y;
	double z;
	double result;

public:
	
	//Get&Set

	double get_x() const {
		return x;
	}

	double get_y() const {
		return y;
	}

	double get_z() const {
		return z;
	}


	double get_result() const {
		return result;
	}

	void set_x(double x) {
		this->x = x;
	}

	void set_y(double y) {
		this->y = y;
	}

	void set_z(double z) {
		this->z = z;
	}

	void set_result(double result) {
		this->result = result;
	}
	//Constructor

	Fraction() {

		x = y = z = result = 1;
		std::cout << "defaultConstructor:\t" << this << std::endl;

	}

	//Constructor

	
	Fraction(double x, double y) {

		this->x = x;
		this->y = y;
		this->result = this->x / this->y;
		std::cout << "2arg Constructor:\t" << this << std::endl;

	}

	Fraction(double x, double y, double z) {

		this->x = x;
		this->y = y;
		this->z = z;
		this->result = this->x / this->y/this->z;
		std::cout << "3arg Constructor:\t" << this << std::endl;

	}

	Fraction& operator = (const Fraction& other) {

		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		this->result = other.result;
		std::cout << "CopyAssignment:\t" << this << std::endl;
		return *this;
	}

	Fraction& operator = (const int& result) {

		this->result = result;
		std::cout << "CopyAssignment:\t" << this << std::endl;
		return *this;
	}

	
	//Destructor

	~Fraction() {
		std::cout << "Destructor:\t" << this << std::endl;

	}

	//Methods

	void print() const {

		std::cout << "Devision result is: " << result << std::endl;
	}
			
};


Fraction& operator * (const Fraction& left, const Fraction& right) {

	Fraction res;
	res.set_x(left.get_x() * right.get_x());
	res.set_y(left.get_y() * right.get_y());
	res.set_z(left.get_z() * right.get_z());
	return res;
}

int main() {

	Fraction A;	//Default onstructor
	A.print();
	Fraction B = 5;
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
	Fraction E = C * D;
	E.print();

	return 0;
}