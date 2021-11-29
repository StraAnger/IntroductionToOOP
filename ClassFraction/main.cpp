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
		if (denominator == 0) {  //�����������
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
		set_denominator(denominator); //������ �� ������ 0 � ���������� ������
		std::cout << "2arg Constructor:\t" << this << std::endl;
	}


	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator); //������ �� ������ 0 � ���������� ������
		std::cout << "3arg Constructor:\t" << this << std::endl;
	}

	//Destructor

	~Fraction()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//Methods

	void to_improper() //��������� ����� � ������������
	{
		numerator += integer * denominator;
		integer = 0;	
	}

	void to_proper() //��������� ����� � ����������
	{
		integer += numerator / denominator;
		numerator %= denominator;
	}



	void print()
	{
		if (integer) {//���� ���� ����� �����, ������� � �� �����
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

	Fraction result
	(
	left.get_numerator() * right.get_numerator(),
	left.get_denominator() * right.get_denominator()
	);
// ��� ����� ���� � ������������, � ����� � ��� ��� ����:

/*	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
*/
	return result;
}

//� ������ Fraction �������� ����� reduce(), ������� ��������� ������� �����.


//#define CONSTRUCTORS_CHECK

int main() {

#ifdef CONSTRUCTORS_CHECK
	Fraction A; //Default constructor
	A.print();
	double b = 5;
	Fraction B = 5; //Single-argument constructor
	B.print();
/*	Fraction C(7); //Single-argument constructor ����� ����� �� 3� ��������
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
	C.print();

	return 0;
}