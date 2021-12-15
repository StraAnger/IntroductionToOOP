#include <iostream>

class String
{
	int size; //размер строки в Ѕайтах- то есть с учЄтом 0л€ терминирующего
	char* str; //јдрес строки в динамической пам€ти

public:

	//Get&seT

	int get_size() const
	{
		return size;
	}


	const char* get_str() const
	{
		return str;
	}

    char* get_str()
	{
		return str;
	}


	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {}; //{}- занул€етс€ пам€ть, выдел€ема€ дл€ строки
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

	String(const String& other)
	{
		//Deep copy ( ѕобитовое копирование ( оно всЄ же побайтовое, но говор€т так)
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; ++i)
			this->str[i] = other.str[i];
		std::cout << "CopyConstructor:\t" << this << std::endl;
	}


	~String()
	{
		delete[] str;
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//	Operators

	String& operator=(const String& other)
	{
		if (this == &other) 
			return *this;      //любой оператор присваивани€ начинаетс€ с этого ( вдруг мы присваиваем сами себе, если так- выходим ( return)), потом удаление старого.
		
		delete[] this->str;  //удал€ем пам€ть от старого объекта
		//Deep copy ( ѕобитовое копирование ( оно всЄ же побайтовое, но говор€т так)
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; ++i)
			this->str[i] = other.str[i];
		std::cout << "CopyAsignment:\t" << this << std::endl;
		return *this;
	}



	//	Methods

	void print() const
	{
		std::cout << "Size:\t" << size << std::endl;
		std::cout << "Str:\t" << str << std::endl;
	}

};

String operator + (const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); ++i)
		result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); ++i)
		result.get_str()[i+ left.get_size()-1] = right.get_str()[i];
	return result;
}


std::ostream& operator << (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}




//#define CONSTRUCTORS_CHECK


int main()
{
#ifdef CONSTRUCTORS_CHECK
	String str1; //Default constructor
	str1.print();
	std::cout << str1 << std::endl;

	String str2(25);
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	std::cout << str3 << std::endl;

	String str4 = str3; //CopyConstructor
	//Deep copy
	//Shallow copy
	std::cout << str4 << std::endl;

	String str5;
	str5 = str3;   //то же самое, что и конструктор копировани€, но уже дл€ существующего объекта
				   //CopyAssignment ( operator=)
	std::cout << str5 << std::endl;
#endif // CONSTRUCTORS_CHECK


	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1+str2;
	std::cout << str3 << std::endl;



	return 0;
}
