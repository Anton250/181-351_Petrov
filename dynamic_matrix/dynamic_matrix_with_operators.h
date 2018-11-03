#include <iostream>
class dynamic_matrix_with_operators {
private:
	int columns;
	int rows;
	double * matr;
public:
	dynamic_matrix_with_operators();

	~dynamic_matrix_with_operators() {
	};

	friend dynamic_matrix_with_operators operator + (dynamic_matrix_with_operators & matr1,
		dynamic_matrix_with_operators matr2);
	friend dynamic_matrix_with_operators operator - (dynamic_matrix_with_operators & matr1,
		dynamic_matrix_with_operators matr2);
	friend dynamic_matrix_with_operators operator * (dynamic_matrix_with_operators & matr1,
		dynamic_matrix_with_operators matr2);
	friend std::ostream & operator << (std::ostream & os, dynamic_matrix_with_operators & matr);
	//dynamic_matrix(const dynamic_matrix & matrix) {

	//};
	void clear() {
		delete[] matr;
		matr = nullptr;
	};

	void setRowsAndColumns(int new_rows, int new_columns);

	int getRows()
	{
		return rows;
	}

	int getColumns()
	{
		return columns;
	}

	//bool summMatrix(dynamic_matrix_with_operators matrix2);

	//bool multMatrix(dynamic_matrix_with_operators matrix2);

	double getElem(int row, int col);

	bool input();

	void transpMatrix();

	void print();
};
