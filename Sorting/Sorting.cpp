#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
int array_for_sorting[20] = {};
int i, j, array_variable;
void bubble_sorting(int * user_array) {
	int count = 0;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 19 - i; j++) {
			if (user_array[j] > user_array[j + 1]) {
				array_variable = user_array[j];
				user_array[j] = user_array[j + 1];
				user_array[j + 1] = array_variable;
			}
		}
		count++;
	}
	std::cout << "Array was sorted by bubble sorting.\n";
	std::cout << "Number of iterations: " << count << std::endl;
	
}
void shaker_sorting(int * user_array){
	int min = 0;
	int max = 19;
	int count = 0;
	while (max > min) {
		for (i = max; i > min; i--) {
			if (user_array[i] < user_array[i - 1]) {
				array_variable = user_array[i];
				user_array[i] = user_array[i - 1];
				user_array[i - 1] = array_variable;
			}
		}
		max--;
		for (i = min; i < max; i++) {
			if (user_array[i] > user_array[i + 1]) {
				array_variable = user_array[i];
				user_array[i] = user_array[i + 1];
				user_array[i + 1] = array_variable;
			}
		}
		min++;
		count++;
	}
	
	std::cout << "Array was sorted by shaker sorting.\n";
	std::cout << "Number of iterations: " << count << std::endl;
}
void print_array(int * arr) {
	for (i = 0; i < 20; i++) {
		std::cout << arr[i] << "\t";
		if ((i + 1) % 5 == 0) {
			std::cout << "\n";
		}
	}
}
int main()
{
	srand(time(NULL)); //Для заполнения массива рандомными числами.
	std::cout << "Array before sorting:\n";
	for (i = 0; i < 20; i++) {
		array_for_sorting[i] = rand() % 100 + 1; //Заполнение массива рандомными числами от 1 до 100.
		std::cout << array_for_sorting[i] << "\t";
		if ((i + 1) % 5 == 0) {
			std::cout << "\n";
		}
	}
	std::cout << "\n";
	shaker_sorting(array_for_sorting);
	print_array(array_for_sorting);
	std::cout << "Array before sorting:\n";
	for (i = 0; i < 20; i++) {
		array_for_sorting[i] = rand() % 100 + 1; //Заполнение массива рандомными числами от 1 до 100.
		std::cout << array_for_sorting[i] << "\t";
		if ((i + 1) % 5 == 0) {
			std::cout << "\n";
		}
	}
	std::cout << "\n";
	bubble_sorting(array_for_sorting);
	print_array(array_for_sorting);
}

