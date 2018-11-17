#include "pch.h"
#include "encrypt_with_many_keys.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


encrypt_with_many_keys::encrypt_with_many_keys()
{
}


encrypt_with_many_keys::~encrypt_with_many_keys()
{
}
void encrypt_with_many_keys::get_str_to_array(std::string user_text_str)
{
	lenght = user_text_str.length();
	user_text_array = new char[lenght + 1];
	strcpy_s(user_text_array, lenght + 1, user_text_str.c_str());
}

int encrypt_with_many_keys::count_of_char_in_file(std::fstream & file_name)
{
	char S[256];
	while (file_name.getline(S, 256)) {
		int k = strlen(S);
		count_of_char += k;
	}
	return count_of_char;
}

int encrypt_with_many_keys::count_of_rows(std::fstream & file_name)
{
	char S[256];
	int k = 0;
	while (file_name.getline(S, 256)) {
		k++;
	}
	file_name.clear();
	file_name.seekg(0, std::ios_base::beg);
	return k;
}

void encrypt_with_many_keys::print(char * user_text_array)
{
	int limit = strlen(user_text_array);
	for (int i = 0; i < limit; i++) {
		std::cout << user_text_array[i];
	}
	std::cout << "\n";
}

void encrypt_with_many_keys::cycle_for_encrypt(char * user_text_array, int limit, char * key, int number_of_char, int * k)
{
	key_lenght = strlen(key);
	for (j = number_of_char; j < limit; j++) {
		if ((user_text_array[j] >= 'A' && user_text_array[j] <= 'Z') ||
			(user_text_array[j] >= 'a' && user_text_array[j] <= 'z')) {
			char_for_array = int(user_text_array[j]);
			shift_number = int(key[number_of_key_char]) - 97;
			char_for_array += shift_number;
			if ((char_for_array > 90 && user_text_array[j] <= 90) || char_for_array > 122) {
				char_for_array -= 26;
			}
			if (number_of_key_char == key_lenght - 1) {
				number_of_key_char = 0;
			}
			else {
				number_of_key_char++;
			}
			user_text_array[j] = char(char_for_array);
			k++;
		}
		else {
			user_text_array[j] = user_text_array[j];
			k++;
		}
	}
}

void encrypt_with_many_keys::cycle_for_decode(char * user_text_array, int limit, char * key, int number_of_char, int * k)
{
	key_lenght = strlen(key);
	for (j = number_of_char; j < limit; j++) {
		if ((user_text_array[j] >= 'A' && user_text_array[j] <= 'Z') ||
			(user_text_array[j] >= 'a' && user_text_array[j] <= 'z')) {
			char_for_array = int(user_text_array[j]);
			shift_number = int(key[number_of_key_char]) - 97;
			char_for_array -= shift_number;
			if ((char_for_array < 97 && user_text_array[j] >= 97) || char_for_array < 65) {
				char_for_array += 26;
			}
			if (number_of_key_char == key_lenght - 1) {
				number_of_key_char = 0;
			}
			else {
				number_of_key_char++;
			}
			user_text_array[j] = char(char_for_array);
			k++;
		}
		else {
			user_text_array[j] = user_text_array[j];
			k++;
		}
	}
}

void encrypt_with_many_keys::encryption(char * user_text_array)
{
	int lenght = strlen(user_text_array);
	otherwise = lenght;
	std::cout << "Number of keys: ";
	std::cin >> number_of_keys;
	std::cin.get();
	lenght_for_one_key = lenght / number_of_keys;
	for (i = 1; i <= number_of_keys; i++) {
		std::cout << "Key number " << i << " ";
		std::cin.getline(key, 20);
		lenght -= lenght_for_one_key;
		limit = lenght_for_one_key * i;
		number_of_char = k;
		number_of_key_char = 0;
		if (lenght >= 0) {
			cycle_for_encrypt(user_text_array, limit, key, number_of_char, &k);
		}
		else {

			cycle_for_encrypt(user_text_array, otherwise, key, number_of_char, &k);
		}

	}
}

void encrypt_with_many_keys::decode(std::string user_text_str)
{
	int lenght = strlen(user_text_array);
	otherwise = lenght;
	std::cout << "Number of keys: ";
	std::cin >> number_of_keys;
	std::cin.get();
	lenght_for_one_key = lenght / number_of_keys;
	for (i = 1; i <= number_of_keys; i++) {
		std::cout << "Key number " << i << " ";
		std::cin.getline(key, 20);
		lenght -= lenght_for_one_key;
		limit = lenght_for_one_key * i;
		number_of_char = k;
		number_of_key_char = 0;
		if (lenght >= 0) {
			cycle_for_decode(user_text_array, limit, key, number_of_char, &k);
		}
		else {
			cycle_for_decode(user_text_array, otherwise, key, number_of_char, &k);
		}

	}
}

void encrypt_with_many_keys::getString()
{
	std::getline(std::cin, user_text_str);
}

void encrypt_with_many_keys::cycle_file_encryption(char * user_text_array)
{
	int limit_for_cycle = strlen(user_text_array);
	key_lenght = strlen(key);
	number_of_key_char = 0;
	for (j = 0; j < limit_for_cycle; j++) {
		if ((user_text_array[j] >= 'A' && user_text_array[j] <= 'Z') ||
			(user_text_array[j] >= 'a' && user_text_array[j] <= 'z')) {
			char_for_array = int(user_text_array[j]);
			shift_number = int(key[number_of_key_char]) - 97;
			char_for_array += shift_number;
			if ((char_for_array > 90 && user_text_array[j] <= 90) || char_for_array > 122) {
				char_for_array -= 26;
			}
			if (number_of_key_char == key_lenght - 1) {
				number_of_key_char = 0;
			}
			else {
				number_of_key_char++;
			}
			user_text_array[j] = char(char_for_array);

		}
		else {
			user_text_array[j] = user_text_array[j];

		}
	}
}

void encrypt_with_many_keys::cycle_file_decode(char * user_text_array)
{
	int limit_for_cycle = strlen(user_text_array);
	key_lenght = strlen(key);
	number_of_key_char = 0;
	for (j = 0; j < limit_for_cycle; j++) {
		if ((user_text_array[j] >= 'A' && user_text_array[j] <= 'Z') ||
			(user_text_array[j] >= 'a' && user_text_array[j] <= 'z')) {
			char_for_array = int(user_text_array[j]);
			shift_number = int(key[number_of_key_char]) - 97;
			char_for_array -= shift_number;
			if ((char_for_array < 97 && user_text_array[j] >= 97) || char_for_array < 65) {
				char_for_array += 26;
			}
			if (number_of_key_char == key_lenght - 1) {
				number_of_key_char = 0;
			}
			else {
				number_of_key_char++;
			}
			user_text_array[j] = char(char_for_array);
		}
		else {
			user_text_array[j] = user_text_array[j];
		}
	}
}

void encrypt_with_many_keys::openUserFile()
{
	std::string file_name;
	std::getline(std::cin, file_name);
	user_file.open(file_name, std::fstream::in);
}

void encrypt_with_many_keys::openDestanationFile()
{
	std::string file_name;
	std::getline(std::cin, file_name);
	end_file.open(file_name, std::fstream::out);
}

void encrypt_with_many_keys::openKeysFile()
{
	std::string file_name;
	std::getline(std::cin, file_name);
	keys_file.open(file_name, std::fstream::in);
}

void encrypt_with_many_keys::encrypt_for_file()
{
	keys_file.open("Keys.txt", std::fstream::out | std::fstream::in);
	int lenght = count_of_rows(user_file);
	otherwise = lenght;
	number_of_keys = count_of_rows(keys_file);
	lenght_for_one_key = lenght / number_of_keys;
	user_file.clear();
	user_file.seekg(0, std::ios_base::beg);
	for (i = 1; i <= number_of_keys; i++) {
		std::getline(keys_file, key_str);
		//get_str_to_arr(key_str, key);
		key = new char[key_str.length() + 1];
		strcpy_s(key, key_str.length() + 1, key_str.c_str());
		lenght -= lenght_for_one_key;
		limit = lenght_for_one_key * i;
		if (lenght < 0) {
			limit = otherwise;
		}
		for (int j = lenght_for_one_key * (i - 1); j < limit; j++) {
			std::getline(user_file, user_text_str, '\n');
			get_str_to_array(user_text_str);
			cycle_file_encryption(user_text_array);
			print(user_text_array);
			for (int k = 0; k < strlen(user_text_array); k++) {
				end_file << user_text_array[k];
			}
			end_file << '\n';
			delete[] user_text_array;
			user_text_array = nullptr;
		}
		delete[] key;
		key = nullptr;
	}
	user_file.close();
	end_file.close();
	keys_file.close();
}

void encrypt_with_many_keys::decode_for_file()
{
	keys_file.open("Keys.txt", std::fstream::out | std::fstream::in);
	int lenght = count_of_rows(user_file);
	otherwise = lenght;
	number_of_keys = count_of_rows(keys_file);
	lenght_for_one_key = lenght / number_of_keys;
	user_file.clear();
	user_file.seekg(0, std::ios_base::beg);
	for (i = 1; i <= number_of_keys; i++) {
		std::getline(keys_file, key_str);
		key = new char[key_str.length() + 1];
		strcpy_s(key, key_str.length() + 1, key_str.c_str());
		lenght -= lenght_for_one_key;
		limit = lenght_for_one_key * i;
		if (lenght < 0) {
			limit = otherwise;
		}
		for (int j = lenght_for_one_key * (i - 1); j < limit; j++) {
			std::getline(user_file, user_text_str, '\n');
			get_str_to_array(user_text_str);
			cycle_file_decode(user_text_array);
			print(user_text_array);
			for (int k = 0; k < strlen(user_text_array); k++) {
				end_file << user_text_array[k];
			}
			end_file << '\n';
			delete[] user_text_array;
			user_text_array = nullptr;
		}
		delete[] key;
		key = nullptr;
	}
	user_file.close();
	end_file.close();
	keys_file.close();
}

