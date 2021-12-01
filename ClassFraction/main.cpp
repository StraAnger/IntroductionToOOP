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
	int get_denominator() const
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

	// Constructors

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "Default constructor:\t" << this << std::endl;
	}

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "1arg Constructor:\t" << this << std::endl;
	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator); //защита от записи 0 и фильтраци€ данных
		std::cout << "2arg Constructor:\t" << this << std::endl;
	}


	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator); //защита от записи 0 и фильтраци€ данных
		std::cout << "3arg Constructor:\t" << this << std::endl;
	}

	//Destructor

	~Fraction()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//Methods

	//¬ классе Fraction написать метод reduce(), который сокращает простую дробь.

	Fraction& reduce() //сокращает простую дробь
	{
		if (!integer) {

			for (int i = numerator + denominator; i > 0 ; --i) {

				if (!(numerator % i) && !(denominator % i)) {
				
					numerator /= i;
					denominator /= i;
				
				}
			}
		}
		else {
			to_improper();
		
			for (int i = numerator + denominator; i > 0 ; --i) {

				if (!(numerator % i) && !(denominator % i)) {

					numerator /= i;
					denominator /= i;

				}
			}
		}
		to_proper();
		return *this;
	}

	Fraction& to_improper() //переводит дробь в неправильную
	{
		numerator += integer * denominator;
		integer = 0;	
		return *this;
	}

	Fraction& to_proper() //переводит дробь в правильную
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction inverted()
	{
		/*Fraction inverted = *this; //inverted это временно
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;*/
		to_improper();
		return Fraction(this->denominator, this->numerator);
	}


	void print()
	{
		if (integer) {//≈сли есть цела€ часть, выводим еЄ на экран
			std::cout << integer;
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


Fraction operator * (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

/*	Fraction result
	(
	left.get_numerator() * right.get_numerator(),
	left.get_denominator() * right.get_denominator()
	);*/
// это сразу если в конструкторе, а можно и так как ниже:

/*	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
*/
//	return result;

	return Fraction //явно вызываем конструктор, который создаЄт временный безым€нный объект
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();

}

Fraction operator / (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction //явно вызываем конструктор, который создаЄт временный безым€нный объект
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper().reduce();

}


//#define CONSTRUCTORS_CHECK

int main() {

#ifdef CONSTRUCTORS_CHECK
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
	Fraction C(3, 4);
	C.print();
	Fraction D(2,3, 4);
	D.print();
#endif CONSTRUCTORS_CHECK

	double a = 2.5;
	double b = 3.4;
	double c = a * b;

	std::cout << c << std::endl;

	Fraction A(2, 1, 2);
	Fraction B(3, 2, 5);
	Fraction C = A * B;
	//Fraction D(0, 840, 3600);
	C.print();
	//std::cout << "Now reduce! " << std::endl;
	//A.reduce();
	//B.reduce();
	C.reduce();
	//D.reduce();
	//A.print();
	//B.print();
	//C.print();
	//D.print();
	C = A / B;
	C.print();

	return 0;
}