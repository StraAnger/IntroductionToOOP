#include "String.h"


/////////////////////////////////////////////////////////////////
/////////////////   Class definition- ����������� ������  ///////
/////////////////////////////////////////////////////////////////


// ::- Scope operator, �������� ���������� ���������

//Get&seT

int String::get_size() const
{
	return size;
}


const char* String::get_str() const
{
	return str;
}

char* String::get_str()
{
	return str;
}


String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {}; //{}- ���������� ������, ���������� ��� ������
	std::cout << "SizeConstructor:\t" << this << std::endl;
}

String::String(const char str[]) :String(strlen(str) + 1) //��� char*- ��� �� �� �����
{
	/*his->size = strlen(str) + 1;
	this->str = new char[size] {};*/
	for (int i = 0; str[i]; ++i)
		this->str[i] = str[i];
	std::cout << "Constructor:\t" << this << std::endl;

}

String::String(const String& other) :String(other.str)
{
	//Deep copy ( ��������� ����������� ( ��� �� �� ����������, �� ������� ���)
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; ++i)
	//	this->str[i] = other.str[i];
	std::cout << "CopyConstructor:\t" << this << std::endl;
}


String::~String()
{
	delete[] str;
	std::cout << "Destructor:\t" << this << std::endl;
}

//	Operators

String& String::operator=(const String& other)
{
	if (this == &other)
		return *this;      //����� �������� ������������ ���������� � ����� ( ����� �� ����������� ���� ����, ���� ���- ������� ( return)), ����� �������� �������.

	delete[] this->str;  //������� ������ �� ������� �������
	//Deep copy ( ��������� ����������� ( ��� �� �� ����������, �� ������� ���)
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; ++i)
		this->str[i] = other.str[i];
	std::cout << "CopyAsignment:\t" << this << std::endl;
	return *this;
}

String& String::operator +=(const String& other)
{
	return *this = *this + other;
}

const char& String::operator[](int i)const
{
	return str[i];
}

char& String::operator[](int i)
{
	return str[i];
}

//	Methods

void String::print() const
{
	std::cout << "Size:\t" << size << std::endl;
	std::cout << "Str:\t" << str << std::endl;
}






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
	char buffer[SIZE] = {};
	is >> buffer;
	obj = buffer;
	return is;
}

std::istream& getline(std::istream& is, String& obj)
{
	const int SIZE = 1024 * 1000;
	char buffer[SIZE] = {};
	is.getline(buffer, SIZE);
	obj = buffer;
	return is;
}



///////////////////////////////////////////////////////////////////////////
/////////////////   Class definition end- ����� ����������� ������  ///////
//////////////////////////////////////////////////////////////////////////
