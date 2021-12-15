#include <iostream>

class Strings
{
	int length;
	char string[80];
	
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
			
			for (int i = 0; i<length; ++i)
			{
				string[i] = ' ';
			}

			
			std::cout << "Default constructor" << std::endl;
		}

		Strings(int length)
		{

			this->length =length;
			for (int i = 0; i <length; ++i)
			{
				this->string[i] = ' ';
			}


			std::cout << "1Arg constructor" << std::endl;
		}

		Strings(const char string[])
		{
			int counter = 0;
			for (int i = 0; string[i]; ++i)
			{
				string[i];
				++counter;
			}
			this->length = counter;
			for (int i = 0; i < length; ++i)
				this->string[i] = string[i];
			counter = 0;
			std::cout << "Type cast constructor" << std::endl;
		}

		Strings(const char string1[], const char string2[])
		{
			int counter1 = 0;
			for (int i = 0; string1[i]; ++i)
			{
				string[i];
				++counter1;
			}

			int counter2 = 0;
			for (int i = 0; string2[i]; ++i)
			{
				string[i];
				++counter2;
			}


			this->length = counter1+counter2;
			
			for (int i = 0; i < counter1; ++i)
				this->string[i] = string1[i];
			
			for (int i = counter1; i < counter2; ++i)
				this->string[i] = string2[i];
			
			
			counter1 = 0;
			counter2 = 0;
			std::cout << "Conc. constructor" << std::endl;
		}


	//Destructor:
		~Strings()
		{
			std::cout << "Destructor" << std::endl;
}
	//Operators:

		

	//Methods:


		void print() const
		{
			for (int i = 0; i < length; ++i)
				std::cout << this->get_string(i);
			std::cout << std::endl;
		}

};


Strings operator + (Strings left, Strings right)
{
	return Strings(left,right);
}


int main()
{
	
	Strings str;	//Empty string with size of 80 bytes
	str.print();
	Strings str1 = "Hello";
	str1.print();
	Strings str2 = "World";
	str2.print();
	Strings str4(25);	//Empty string with size of 25 bytes
	str4.print();
	


	

	//String str3 = str1 + str2;
	//std::cout << str3 << std::endl;

	


	return 0;
}