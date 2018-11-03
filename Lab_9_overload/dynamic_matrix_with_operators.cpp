#include "pch.h"
#include "dynamic_matrix_with_operators.h"


dynamic_matrix_with_operators::dynamic_matrix_with_operators()
{
}

void dynamic_matrix_with_operators::setRowsAndColumns(int new_rows, int new_columns)
{
	rows = new_rows;
	columns = new_columns;
	matr = new double[rows*columns];
}

double dynamic_matrix_with_operators::getElem(int row, int col)
{
	if (row <= rows && col <= columns && row > -1 && col > -1) {
		return matr[row * columns + col];
	}
	std::cout << "Index Error!\n";
	return -1;
}

bool dynamic_matrix_with_operators::input()
{
	std::cin >> rows;
	if (rows <= 0) {
		return false;
	}
	std::cin >> columns;
	if (columns <= 0) {
		return false;
	}

	matr = new double[columns*rows];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cin >> matr[i * columns + j];
		}
	}
	return true;
}

void dynamic_matrix_with_operators::transpMatrix()
{
	int k = 0;
	double * matrix3 = new double[rows * columns];
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			matrix3[k] = matr[j * columns + i];
			k++;
		}
	}
	for (int i = 0; i < columns*rows; i++) {

		matr[i] = matrix3[i];
	}
	delete[] matrix3;
	matrix3 = nullptr;
	int temporary = columns;
	columns = rows;
	rows = temporary;

}

void dynamic_matrix_with_operators::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matr[i * columns + j] << "\t";
		}
		std::cout << "\n";
	}
}

dynamic_matrix_with_operators operator +(dynamic_matrix_with_operators & matr1, dynamic_matrix_with_operators matr2)
{
	dynamic_matrix_with_operators result_matrix;
	if ((matr1.getColumns() == matr2.getColumns()) && (matr1.getRows() == matr2.getRows())) {
		result_matrix.setRowsAndColumns(matr1.getRows(), matr1.getColumns());
		for (int i = 0; i < matr1.getColumns(); i++) {
			for (int j = 0; j < matr1.getRows(); j++) {
				result_matrix.matr[i*matr1.getColumns() + j] = matr1.getElem(i, j) + matr2.getElem(i, j);
			}
		}
		return result_matrix;
	}
	else {
		std::cout << "Error!";
		return dynamic_matrix_with_operators::dynamic_matrix_with_operators();
	}
}

dynamic_matrix_with_operators operator-(dynamic_matrix_with_operators & matr1, dynamic_matrix_with_operators matr2)
{
	dynamic_matrix_with_operators result_matrix;
	result_matrix.setRowsAndColumns(matr1.getRows(), matr1.getColumns());
	if ((matr1.getColumns() == matr2.getColumns()) && (matr1.getRows() == matr2.getRows())) {
		for (int i = 0; i < matr1.getColumns(); i++) {
			for (int j = 0; j < matr1.getRows(); j++) {
				result_matrix.matr[i*matr1.getColumns() + j] = matr1.getElem(i, j) - matr2.getElem(i, j);
			}
		}
		return result_matrix;
	}
	else {
		std::cout << "Error!";
		return dynamic_matrix_with_operators::dynamic_matrix_with_operators();
	}
}

dynamic_matrix_with_operators operator *(dynamic_matrix_with_operators & matr1, dynamic_matrix_with_operators matr2)
{
	dynamic_matrix_with_operators result_matrix;
	result_matrix.setRowsAndColumns(matr1.getRows(), matr2.getColumns());
	//double * matrix3 = new double[matr2.getColumns()*matr1.rows];
	if (matr1.getColumns() == matr2.getRows()) {
		for (int i = 0; i < matr1.getRows(); i++) {
			for (int j = 0; j < matr2.getColumns(); j++) {
				double sum = 0;
				for (int k = 0; k < matr1.getColumns(); k++) {
					sum += matr1.getElem(i, k) * matr2.getElem(k, j);
				}
				result_matrix.matr[i * matr2.getColumns() + j] = sum;
			}
		}
		return result_matrix;
	}
	else {
		std::cout << "Error!";
		return dynamic_matrix_with_operators::dynamic_matrix_with_operators();
	}
}


std::ostream & operator<<(std::ostream & os, dynamic_matrix_with_operators & matr) {
	for (int i = 0; i < matr.getRows(); i++) {
		for (int j = 0; j < matr.getColumns(); j++) {
			os << matr.matr[i * matr.getColumns() + j] << "\t";
		}
		os << "\n";
	}
	return os;
}