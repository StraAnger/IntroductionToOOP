#include <iostream>

#define delimiter "\n---------------------------------------------------------\n"

class String;
String operator + (const String& left, const String& right);

class String
{
	int size; //размер строки в Байтах- то есть с учётом 0ля терминирующего
	char* str; //Адрес строки в динамической памяти

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

	String(const String& other)
	{
		//Deep copy ( Побитовое копирование ( оно всё же побайтовое, но говорят так)
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; ++i)
			this->str[i] = other.str[i];
		std::cout << "CopyConstructor:\t" << this << std::endl;
	}

	String(String&& other)noexcept
	{
		//MoveConstructor должен выполнять shallowCopy- поверхностное копирование
		//пока не написали- вызывался CopyConstructor
		this->size = other.size;
		this->str = other.str;   // просто копируем адрес памяти, принадлежащий другому объекту
		//Зануляем другой объект для того, чтобы его память не смог удалить деструктор ( иначе упадёт всё)
		other.size = 0;
		other.str = nullptr;
		std::cout << "MoveConstructor\t" << this << std::endl;
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
			return *this;      //любой оператор присваивания начинается с этого ( вдруг мы присваиваем сами себе, если так- выходим ( return)), потом удаление старого.
		
		delete[] this->str;  //удаляем память от старого объекта
		//Deep copy ( Побитовое копирование ( оно всё же побайтовое, но говорят так)
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; ++i)
			this->str[i] = other.str[i];
		std::cout << "CopyAsignment:\t" << this << std::endl;
		return *this;
	}

	String& operator=(String&& other)
	{

		if (this == &other)
			return *this;

		delete this->str;
		this->size = other.size;
		this->str = other.str;

		other.size = 0;
		other.str = nullptr;
		std::cout << "MoveAssignment:\t" << this << std::endl;
		return  *this;
	}


	String& operator +=(const String& other)
	{
		return *this = *this + other;
	}

	const char& operator[](int i)const
	{
		return str[i];
	}

	char& operator[](int i)
	{
		return str[i];
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
		//l-value=r-value;
		result[i] = left[i];
		//result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); ++i)
		result[i + left.get_size() - 1] = right[i];
		//result.get_str()[i+ left.get_size()-1] = right.get_str()[i];
	return result;
}


std::ostream& operator << (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

std::istream& operator >> (std::istream& is, String& obj)
{
	//return is >> obj.get_str();
	const int SIZE = 10240;
	char buffer[ SIZE ] = {};
	is >> buffer;
	obj = buffer;
	return is;
}

std::istream& getline (std::istream& is, String& obj)
{
	const int SIZE = 1024 * 1000;
	char buffer[SIZE] = {};
	is.getline(buffer, SIZE);
	obj = buffer;
	return is;
}

//#define CONSTRUCTORS_CHECK
#define OPERATORS_CHECK

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
	str5 = str3;   //то же самое, что и конструктор копирования, но уже для существующего объекта
				   //CopyAssignment ( operator=)
	std::cout << str5 << std::endl;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATORS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	std::cout << delimiter << std::endl;
	String str3;
	str3 = str1 + str2;
	std::cout << delimiter << std::endl;
	std::cout << str3 << std::endl;
	std::cout << delimiter << std::endl;
	/*str1 += str2;
	std::cout << delimiter << std::endl;
	std::cout << str1 << std::endl;
	std::cout << delimiter << std::endl;*/
#endif // OPERATORS_CHECK

	
	//String str;
	//std::cout << "Enter string: ";
	////std::cin >> str;
	//getline(std::cin, str);
	//std::cout << str << std::endl;
	//str.print();
	//std::cout << delimiter << std::endl;

	return 0;
}
