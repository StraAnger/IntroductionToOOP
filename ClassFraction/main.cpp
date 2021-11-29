#include <iostream>



class Fraction 
{

	int integer;
	int numerator;
	int denominator;
public:
	int get_integer() const 
	{
		return integer;
    }
	int get_numerator() const 
	{
		return numerator;
	}
	int get_denumerator() const
	{
		return denominator;
	}

	void set_integer(int integer) 
	{
		this->integer;
	}
	void set_numerator(int numerator) 
	{
		this->numerator;
	}
	void set_denominator(int denominator) 
	{
		if (denominator == 0) {  //знаменатель
			denominator = 1;
		}
		this->denominator=denominator;
	}

	// Constructor

	Fraction(int integer = 0, int numerator = 0, int denominator = 1)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		std::cout << "Constructor:\t" << this << std::endl;
	}

	//Destructor

	~Fraction()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//Methods

	void print()
	{
		if (integer) {//Если есть целая часть, выводим её на экран
			std::cout << integer << std::endl;
		}
		if (numerator) {
			if (integer) {
				std::cout << "(";
			}
			std::cout << numerator<<" / "<< denominator;
			if (integer) {
				std::cout << ")";
			}
		}
		else if (integer == 0) {
			std::cout << 0;
		}
		std::cout << std::endl;

	}




};



int main() {


	Fraction A; //Default constructor
	A.print();
	double b = 5;
	Fraction B = 5; //Single-argument constructor
	B.print();
/*	Fraction C(7); //Single-argument constructor можно любым из 3х способов
	C.print();
	Fraction D{ 8 }; //Single-argument constructor
	D.print();
*/

	return 0;
}