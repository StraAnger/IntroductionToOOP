#include <iostream>

class String
{
	int size; //размер строки в Байтах- то есть с учётом 0ля терминирующего
	char* str; //Адрес строки в динамической памяти

public:

	//Get&seT

	const char* get_str()const
	{
		return str;
	}


	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {}; //{}- зануляется память, выделяемая для строки
		std::cout << "Constructor:\t" << this << std::endl;
	}

	String(const char str[])   //или char*- это то же самое
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; ++i)
			this->str[i] = str[i];
		std::cout << "Constructor:\t" << this << std::endl;

	}


	~String()
	{
		delete[] str;
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//	Methods

	void print() const
	{
		std::cout << "Size:\t" << size << std::endl;
		std::cout << "Str:\t" << str << std::endl;
	}

};


std::ostream& operator << (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}


int main()
{
	String str1; //Default constructor
	str1.print();
	std::cout << str1 << std::endl;

	String str2(25);
	str2.print();

	String str3 = "Hello";
	std::cout << str3 << std::endl;


	return 0;
}
