
#include "pch.h"
#include <iostream>

class matrix {
private:
	double matr[10][10];
	int columns;
	int rows;
public:
	matrix();

	~matrix();

	int getRows()
	{
		return rows;
	}

	int getColumns()
	{
		return columns;
	}

	bool summMatrix(matrix matrix2);

	bool multMatrix(matrix matrix2); 

	double getElem(int row, int col);

	bool input();

	void transpMatrix();

	void print();
};
class vector : public matrix{
private:
	int n;
	double vec[10];
public:
	double scalMultVector(vector vec2);
	double getElem(int n); 
	void vecMult(double k);
	bool input();
	void print();
};

int main()
{ 
	matrix matrA, matrB;
	matrA.input();
	
	matrA.transpMatrix();
	matrA.print();
   
}

matrix::matrix()
{
}

matrix::~matrix()
{
}

bool matrix::summMatrix(matrix matrix2)
{
	if ((columns == matrix2.getColumns()) && (rows == matrix2.getRows())) {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				matr[i][j] += matrix2.getElem(i, j);
			}
		}
		return true;
	}
	else {
		return false;
	}
}

bool matrix::multMatrix(matrix matrix2)
{
	double matrix3[10][10];
	if (columns == matrix2.getRows()) {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < matrix2.getRows(); j++) {
				double sum = 0;
				for (int k = 0; k < columns; k++) {
					sum += matr[i][k] * matrix2.getElem(k, j);
				}
				matrix3[i][j] = sum;
			}
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matr[i][j] = 0;
			}
		}
		rows = columns;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matr[i][j] = matrix3[i][j];
			}
		}

		return true;
	}
	else {
		return false;
	}
}

double matrix::getElem(int row, int col)
{
	if (row <= rows && col <= columns && row > -1 && col > -1) {
		return matr[row][col];
	}
	std::cout << "Index Error!\n";
	return -1;
}

bool matrix::input()
{
	std::cin >> rows;
	if (rows >= 10 || rows <= 0) {
		return false;
	}
	std::cin >> columns;
	if (columns >= 10 || columns <= 0) {
		return false;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cin >> matr[i][j];
		}
	}
	return true;
}

void matrix::transpMatrix()
{
	if (rows != columns) {
		int temporary = columns;
		columns = rows;
		rows = temporary;
	}
	for (int i = 0; i < columns; i++) {
		for (int j = i; j < rows; j++) {
			double temporary = matr[j][i];
			matr[j][i] = matr[i][j];
			matr[i][j] = temporary;
		}
	}
}

void matrix::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matr[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

double vector::scalMultVector(vector vec2)
{
	if (n == vec2.n) {
		double sum = 0;
		for (int i = 0; i < n; i++) {
			sum += vec[i] * vec2.getElem(i);
		}
		return sum;
	}
	else {
		std::cout << "Error!";
		return -1;
	}
}

double vector::getElem(int n)
{
	if (n < 10 && n > -1) {
		return vec[n];
	}
	return -1;
}

void vector::vecMult(double k)
{ 
	for (int i = 0; i < n; i++) {
		vec[i] *= k;
	}

}

bool vector::input()
{
	std::cin >> n;
	if (n >= 10 || n <= 0) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}
	return true;
}

void vector::print()
{
	for (int i = 0; i < n; i++) {
		std::cout << vec[i] << "\n";
}
}
