#include <iostream>

class Strings
{
	int length;
	char string[];
	
public:

	//Get&seT:
		char get_string(int i) const
	{
			return string[i];
	}
	    void set_string(int i)
	{
			this->string[i]=string[i];
	}

	//Constructors:

		Strings()
		{
			
			this->length = 80;
			for (int i = 0; i<50; ++i)
			{
				string[i] = '1';
			}

			
			std::cout << "Default constructor" << std::endl;
		}

		Strings(int length)
		{

			this->length =length;
			for (int i = 0; i < 50; ++i)
			{
				this->string[i] = '2';
			}


			std::cout << "1Arg constructor" << std::endl;
		}


	//Destructor:
		~Strings()
		{
			std::cout << "Destructor" << std::endl;
}
	//Operators:

		/*String& operator=(const String& other)
		{
			this->string[i] = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;
			cout << "CopyAssignment:\t" << this << endl;
			return *this;
		}*/

	//Methods:


		void print() const
		{
			for (int i = 0; i < 50; ++i)
				std::cout << this->get_string(i);
			std::cout << std::endl;
		}

};


int main()
{
	
	Strings str;
//	str.print();


	//String str;	//Empty string with size of 80 bytes
	//String str1 = "Hello";
	//String str2 = "World";
	//String str3 = str1 + str2;
	//std::cout << str3 << std::endl;

	//String str4(25);	//Empty string with size of 25 bytes


	return 0;
}