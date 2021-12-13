#include <iostream>

class Fraction;
Fraction operator * (Fraction left, Fraction right);//Объявляем функцию.
Fraction operator / (Fraction left, Fraction right);
Fraction operator + (Fraction left, Fraction right);
Fraction operator - (Fraction left, Fraction right);
Fraction operator == (Fraction left, Fraction right);
Fraction operator != (Fraction left, Fraction right);
Fraction operator > (Fraction left, Fraction right);
Fraction operator < (Fraction left, Fraction right);
Fraction operator >= (Fraction left, Fraction right);
Fraction operator <= (Fraction left, Fraction right);

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
		this->integer=integer;
	}
	void set_numerator(int numerator) 
	{
		this->numerator=numerator;
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

	Fraction(double input)
	{
		denominator = 1;
		while (int(input)!=input)
		{
			this->integer = 0;
			this->numerator = input * 10;
			this->denominator *= 10;
			input *= 10;
		}
		to_proper().reduce();

		std::cout << "1arg Constructor for double:\t" << this << std::endl;
	
	    //decimal +=1e-11; //корректировка неточного результата
		//integer = decimal;
		//denominator = 1e+9;
		//decimal -= integer; //Убираем целую часть из 10чной дроби
        //numerator = decimal*denominator;
		//reduce();
				
	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator); //защита от записи 0 и фильтрация данных
		std::cout << "2arg Constructor:\t" << this << std::endl;
	}


	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator); //защита от записи 0 и фильтрация данных
		std::cout << "3arg Constructor:\t" << this << std::endl;
	}

	//Destructor

	~Fraction()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//Operators

	Fraction& operator = (const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "Copy assignment:\t" << this << std::endl;
		return *this;
	}

	Fraction& operator += (Fraction& other)
	{
		return *this = *this + other;
	}

	Fraction& operator -= (Fraction& other)
	{
		return *this = *this - other;
	}

	Fraction& operator *= (const Fraction& other)
	{
		return *this = *this * other;
	}

	Fraction& operator /= ( Fraction& other)
	{
		return *this = *this * other.inverted();
	}




	// Type-cast operators;

	explicit operator int() const
	{
		return integer;
	}

	explicit operator double() const
	{
		/*to_improper();

		return double(numerator)/double(denominator);
		*/

		return integer + (double)numerator / denominator;

	}


	//Methods

	//В классе Fraction написать метод reduce(), который сокращает простую дробь.

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


	std::ostream& print(std::ostream& os) const
	{
		if (integer) {//Если есть целая часть, выводим её на экран
			os << integer;
		}
		if (numerator) {
			if (integer) {
				os << "(";
			}
			os << numerator<<" / "<< denominator;
			if (integer) {
				os << ")";
			}
		}
		else if (integer == 0) {
			os << 0;
		}
		return os;

	}
};

Fraction operator + (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
		

return Fraction //Явно вызываем конструктор, который создаёт временный безымянный объект
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();

}

Fraction operator - (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();


	return Fraction //Явно вызываем конструктор, который создаёт временный безымянный объект
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();

}


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

	return Fraction //Явно вызываем конструктор, который создаёт временный безымянный объект
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();

}

Fraction operator / (Fraction left, Fraction right)
{
	return left * right.inverted();
}



Fraction operator == (Fraction left,Fraction right)
{
	left.to_improper();
	right.to_improper();

	return (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator());
}

Fraction operator != (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return (left.get_numerator() * right.get_denominator() != right.get_numerator() * left.get_denominator());
}

Fraction operator > (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	if (left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator())
	{
     	return true;
	}
	return false;
}

Fraction operator < (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	if (left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator())
	{
		return true;
	}
	return false;
}

Fraction operator >= (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	if (left.get_numerator() * right.get_denominator() >= right.get_numerator() * left.get_denominator())
	{
		return true;
	}
	return false;
}

Fraction operator <= (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	if (left.get_numerator() * right.get_denominator() <= right.get_numerator() * left.get_denominator())
	{
		return true;
	}
	return false;
}

std::ostream& operator << (std::ostream& os, const Fraction& obj)
{
	//if (obj.get_integer()) {//Если есть целая часть, выводим её на экран
	//	os << obj.get_integer();
	//}
	//if (obj.get_numerator()) {
	//	if (obj.get_integer()) {
	//		os << "(";
	//	}
	//	os << obj.get_numerator() << " / " << obj.get_denominator();
	//	if (obj.get_integer()) {
	//		os << ")";
	//	}
	//}
	//else if (obj.get_integer() == 0) {
	//	os << 0;
	//}
	//return os;

	return obj.print(os);

}

std::istream& operator >> (std::istream& is, Fraction& obj)
{
	obj = Fraction(); //обнуляем объект
	const int SIZE = 256;
	char buffer[SIZE] = {};
	char delimiters[] = "() /";
	is.getline(buffer, SIZE);
	char* number[3] = {}; //Этот массив будет хранить части строки, полученные при помощи strtok
	int n = 0; //Индекс элемента в массиве number

	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[n++] = pch;
	}

	switch (n)
	{
	case 1: obj.set_integer(atoi(number[0]));
		break;
	case 2: obj.set_numerator(atoi(number[0]));
		obj.set_denominator(atoi(number[1]));
		break;
	case 3: 
		obj.set_integer(atoi(number[0]));
		obj.set_numerator(atoi(number[1]));
		obj.set_denominator(atoi(number[2]));
	}

	return is;
}

//#define CONSTRUCTORS_CHECK
//define OPERATORS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
//#define HOME_WORK


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
	Fraction D(2, 3, 4);
	D.print();
#endif CONSTRUCTORS_CHECK
#ifdef OPERATORS_CHECK

	double a = 2.5;
	double b = 3.4;
	double c = a * b;

	std::cout << c << std::endl;

	Fraction A(2, 1, 2);
	Fraction B(3, 2, 5);
	//Fraction C = A * B;
	//Fraction D(0, 840, 3600);
	//C.print();
	//std::cout << "Now reduce! " << std::endl;
	//A.reduce();
	//B.reduce();
	//C.reduce();
	//D.reduce();
	//A.print();
	//B.print();
	//C.print();
	//D.print();
	//C = A / B;
	//C.print();

	A *= B;
	A.print();

#endif // OPERATORS_CHECK
#ifdef TYPE_CONVERSIONS_BASICS

	int a = 2;    //no coversion
	double b = 3; //From less to more
	int c = b;    //From more to less without data loss
	int d = 4.5;  //From more to less with data loss  
#endif // TYPE_CONVERSIONS_BASICS
#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS

	double a = 2;      //From 'int' to 'double'
	Fraction A = 5;    //From 'int' to 'Fraction'
					   //Single-argument constructor
	A.print();

	Fraction B;
	B = 8;              //CopyAssignment
	B = Fraction(8);
	B.print();

	//Fraction C = 12; //explicit constructor невозможно вызвать так

	Fraction C(12); //НО explicit constructor всегда можно вызвать так

	Fraction D{ 13 }; //или так

	// Type- cast operators;
/*	operator type()
	{
		......
		......
	}
*/
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS
#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER
	Fraction A(2);
	//int a = A;



	std::cout << a << std::endl;

	int i = (int)A; //or
	int i = int(A); //or  
#endif // CONVERSIONS_FROM_CLASS_TO_OTHER
#ifdef HOME_WORK
	Fraction A(2, 3, 4);
	double a = A;
	std::cout << a << std::endl;


	double b = 2.75;
	Fraction B = b;
	B.print();
#endif // HOME_WORK

	//Fraction A(2, 3, 4);
	//std::cout << A << std::endl;
	


    //Перегрузить оператор ввода :
	Fraction A;
	std::cout << "Enter the simple fraction: "; 
	std::cin >> A;
	std::cout << A << std::endl;
	
		
	return 0;
}