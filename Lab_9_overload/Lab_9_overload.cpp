
#include "pch.h"
#include <iostream>
#include "dynamic_matrix_with_operators.h"
//Перегрузка функций, методов и операторов
//Перегрузка - объявление нескольких функций
//(а так же методов классов и операторов, которые 
/*
matrix & matrix::operator += (matrix & second_matr){
this-> setElem(i, j, first_matr[i][j] + second_matr.getElem(i, j))
return (*this);
}
matrix operator +;

*/
class dynamic_vector : public dynamic_matrix_with_operators {
private:
	int columns = 1;
	int rows;
	double * vector;
public:
	void input();
};
int main()
{
	dynamic_matrix_with_operators matr1, matr2, matr3;
	dynamic_vector vec1, vec2, vec3;
	vec1.input();
	vec2.input();
	(vec1 + vec2).print();

	//matr1.input();
	//matr1.print();
	//matr2.input();
	//matr3 = matr1 + matr2;
	//std::cout << matr3 << std::endl;
	//matr3 = matr1 * matr2;
	//std::cout << matr3 << std::endl;
	//matr1.multMatrix(matr2);
	//matr1.summMatrix(matr2);
	//matr1.transpMatrix();
	//matr1.print();
	//matr1.clear();
	//matr2.clear();
	return 0;

}

void dynamic_vector::input()
{
	std::cin >> rows;
	vector = new double[rows];
	for (int i = 0; i < rows; i++) {
		std::cin >> vector[i];
	}
}
