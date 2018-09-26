#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
int array_for_sorting[20] = {};
int i, j, array_variable;
void bubble_sorting(int user_array[20]) {
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 19 - i; j++) {
			if (user_array[j] > user_array[j + 1]) {
				array_variable = user_array[j];
				user_array[j] = user_array[j + 1];
				user_array[j + 1] = array_variable;
			}
		}
	}
	std::cout << "Array was sorted by bubble sorting.\n";
	for (i = 0; i < 20; i++) {
		std::cout << user_array[i] << "\t";
		if ((i + 1) % 5 == 0) {
			std::cout << "\n";
		}
	}
}
void shaker_sorting(int user_array[20]){
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 19 - i; j++) {
			if (user_array[j] > user_array[j + 1]) {
				array_variable = user_array[j];
				user_array[j] = user_array[j + 1];
				user_array[j + 1] = array_variable;
			}
		}
		for (j = 19; j > 0 + i; j--) {
			if (user_array[j] < user_array[j - 1]) {
				array_variable = user_array[j];
				user_array[j] = user_array[j - 1];
				user_array[j - 1] = array_variable;
			}
		}
	}
	std::cout << "Array was sorted by shaker sorting.\n";
	for (i = 0; i < 20; i++) {
		std::cout << user_array[i] << "\t";
		if ((i + 1) % 5 == 0) {
			std::cout << "\n";
		}
	}
}
int main()
{
	srand(time(NULL));
	std::cout << "Array before sorting:\n";
	for (i = 0; i < 20; i++) {
		array_for_sorting[i] = rand() % 100 + 1;
		std::cout << array_for_sorting[i] << "\t";
		if ((i + 1) % 5 == 0) {
			std::cout << "\n";
		}
	}
	std::cout << "\n";
	bubble_sorting(array_for_sorting);
	std::cout << "\n";
	shaker_sorting(array_for_sorting);
}

