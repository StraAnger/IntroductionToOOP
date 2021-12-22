#include "String.h"

#define delimiter "\n---------------------------------------------------------\n"

//#define CLASS_MATRIX
#ifdef CLASS_MATRIX
	
class Matrix
{
	int rows;
	int columns;
	int** matrix;

public:

	//Get&Set

	int getRows()const
	{
		return rows;
	}
	int getColumns()const
	{
		return columns;
	}
	int** getMatrix()const
	{
		return matrix;
	}

	//Constructors

	explicit Matrix(int rows = 3, int columns = 3)
	{
		this->rows = rows;
		this->columns = columns;
		this->matrix = new int* [rows];
		for (int i = 0; i < rows; ++i)
			matrix[i] = new int[columns];
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < columns; ++j)
			{
				matrix[i][j] = 0;
			}

		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}

	//Destructor

	~Matrix()
	{
		for (int i = 0; i < rows; ++i)
			delete matrix[i];
		delete[] matrix;
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//Operators

	const int& operator[](int i)const
	{
		return *matrix[i];
	}

	int& operator[](int i)
	{
		return *matrix[i];
	}

	//Methods

	void print() const
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
				std::cout << matrix[i][j] << " ";
			std::cout << std::endl;
		}
	}

};

Matrix operator + (const Matrix& left, const Matrix& right)
{
	if ((left.getRows() != right.getRows()) || (left.getColumns() != right.getColumns()))
	{
		std::cout << "Matrix of different dimension!!! + not allowed" << std::endl;
		exit(0);
	}

	Matrix sumMatrix(left.getRows(), left.getColumns());

	for (int i = 0; i < left.getRows(); ++i) {
		for (int j = 0; j < left.getColumns(); ++j) {
			sumMatrix[j] = left[j] + right[j];
		}

	}

	return sumMatrix;
}
#endif // CLASS_MATRIX




//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
//#define INPUT_CHECK
//#define MATRIX_CHECK

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


#ifdef MATRIX_CHECK

	Matrix A;
	A.print();


#endif // MATRIX_CHECK

	return 0;
}
