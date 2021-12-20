#include "String.h"
#define delimiter "\n---------------------------------------------------------\n"


//////--------------------------------------------------------------------------


///Methods out of Class


//#define CONSTRUCTORS_CHECK
#define OPERATORS_CHECK
//#define INPUT_CHECK


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
	String str3 = str1 + str2;
	std::cout << delimiter << std::endl;
	std::cout << str3 << std::endl;
	std::cout << delimiter << std::endl;
	str1 += str2;
	std::cout << delimiter << std::endl;
	std::cout << str1 << std::endl;
	std::cout << delimiter << std::endl;
#endif // OPERATORS_CHECK

	
#ifdef INPUT_CHECK
	String str;
	std::cout << "Enter string: ";
	//std::cin >> str;
	getline(std::cin, str);
	std::cout << str << std::endl;
	str.print();
	std::cout << delimiter << std::endl;
#endif // INPUT_CHECK


	return 0;
}
