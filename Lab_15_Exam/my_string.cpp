//#define _CRT_SECURE_NO_WARNINGS
#include "my_string.h"
#include<string>
#include<iostream>
#include<stdio.h>
#include <openssl/conf.h> // функции, структуры и константы настройки OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // сами криптогрфические функции https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // коды внутренних ошибок OpenSSL и их расшифровка
#include <openssl/aes.h>
#include <fstream>
#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")
my_string::my_string()
{
	str = new char[0];
}

my_string::my_string(char* arr)
{
	len = strlen(arr);
	str = new char[len+1];
	strcpy_s(str, len + 1, arr);
}

my_string::my_string(std::string arr)
{
	len = arr.length();
	str = new char[len+1];
	
	strcpy_s(str, len+1, arr.c_str());
}

my_string::my_string(my_string & arr)
{
	len = arr.len;
	
	str = new char[len+1];
	
	for (int i = 0; i < len+1; i++) {
		str[i] = arr.str[i];
	}
}

my_string::~my_string()
{
}

void my_string::clear()
{
	len = 0;
	delete[] str;
	str = nullptr;
}

void my_string::add(char * arr)
{
	char* temp1 = new char[len + 1];
	strcpy_s(temp1, len + 1, str);
	delete[] str;
	str = nullptr;
	len += strlen(arr);
	str = new char[len + 1];
	strcpy_s(str, strlen(temp1) + 1, temp1);
	strcat_s(str, len + 1, arr);
	delete[] temp1;
	temp1 = nullptr;
}

void my_string::add(std::string arr)
{
	
	std::string temp = (std::string) str;
	temp += arr;
	len = temp.length();
	delete[] str;
	str = nullptr;
	str = new char[len+1];
	for (int i = 0; i < len+1; i++) {
		str[i] = temp[i];
	}
}

int my_string::insert(int pos, char * arr)
{
	if (pos <= len) {
		char * temp1 = new char[pos];
		char * temp3 = new char[len - pos];
		for (int i = 0; i < pos; i++) {
			temp1[i] = str[i];
		}
		temp1[pos] = '\0';
		for (int i = pos; i < pos + len; i++) {
			temp3[i - pos] = str[i];
		}
		temp3[len - pos] = '\0';
		len += strlen(arr);
	
		delete[] str;
		str = nullptr;
		str = new char[len+1];

		for (int i = 0; i < pos; i++) {
			str[i] = temp1[i];
		}
		str[pos] = '\0';

		for (int i = pos; i < pos + strlen(arr); i++) {
			str[i] = arr[i - pos];
		}
		str[pos + strlen(arr)] = '\0';

		for (int i = pos + strlen(arr); i < len; i++) {
			str[i] = temp3[i - pos - strlen(arr)];
		}
		str[len] = '\0';
		
		return 0;
	} 
	return -1;
}

int my_string::insert(int pos, std::string arr)
{
	if (pos <= len) {
		char * temp1 = new char[pos];
		char * temp3 = new char[len - pos];
		for (int i = 0; i < pos; i++) {
			temp1[i] = str[i];
		}
		temp1[pos] = '\0';
		for (int i = pos; i < pos + len; i++) {
			temp3[i - pos] = str[i];
		}
		temp3[len - pos] = '\0';
		len += arr.length();

		delete[] str;
		str = nullptr;
		str = new char[len + 1];

		for (int i = 0; i < pos; i++) {
			str[i] = temp1[i];
		}
		str[pos] = '\0';

		for (int i = pos; i < pos + arr.length(); i++) {
			str[i] = arr[i - pos];
		}
		str[pos + arr.length()] = '\0';

		for (int i = pos + arr.length(); i < len; i++) {
			str[i] = temp3[i - pos - arr.length()];
		}
		str[len] = '\0';

		return 0;
}   
	return -1;
}

int my_string::cut(int pos, int count)
{
	if (pos + count <= len) {
		char * temp1 = new char[pos];
		char * temp2 = new char[len - count - pos];
		for (int i = 0; i < pos; i++) {
			temp1[i] = str[i];
		}
		temp1[pos] = '\0';
		for (int i = pos + count; i < len; i++) {
			temp2[i - pos - count] = str[i];
		}
		temp2[len - count - pos] = '\0';
		len -= count;
		delete[] str;
		str = nullptr;
		str = new char[len + 1];
		for (int i = 0; i < pos; i++) {
			str[i] = temp1[i];
		}
		str[pos] = '\0';
		for (int i = pos; i < len; i++) {
			str[i] = temp2[i - pos];
		}
		str[len] = '\0';
		return 0;
	}
	return -1;
}

int my_string::lenght()
{
	return len;
}

my_string operator+(my_string & arr1, my_string arr2)
{
	my_string result_arr;
	result_arr.len = arr1.lenght() + arr2.lenght();
	result_arr.str = new char[arr1.lenght() + arr2.lenght() + 1];
	for (int i = 0; i < arr1.lenght(); i++) {
		result_arr.str[i] = arr1.str[i];
	}
	result_arr.str[arr1.lenght()] = '\0';
	for (int i = arr1.lenght(); i < arr1.lenght() + arr2.lenght(); i++) {
		result_arr.str[i] = arr2.str[i - arr1.lenght()];
	}
	result_arr.str[arr1.lenght() + arr2.lenght()] = '\0';

	return result_arr;
}
void my_string:: array_equalization(char * first_array, char * second_array) {
	int lenght = strlen(first_array);
	for (int i = 0; i < lenght; i++) {
		second_array[i] = first_array[i];
	}
}

void my_string::cat_str(char * dest, int len, char * source)
{
	int arr_len = strlen(source);
	int lenght = strlen(dest);
	
	
		for (int i = lenght; i < len + lenght; i++) {
			dest[i] = source[i - lenght];
		}
	
}

char my_string::at(int i)
{
	return str[i];
}

int my_string::crypto()
{
	char * crypted_text = new char[len + len];
	int crypted_len = 0;
	int lenght;
	unsigned char *key = (unsigned char *)"0123456789"; 
	unsigned char *iv = (unsigned char *)"0123456789012345";
	EVP_CIPHER_CTX *ctx;
	ctx = EVP_CIPHER_CTX_new();
	EVP_EncryptInit_ex(ctx, 
		EVP_aes_256_cbc(), 
		NULL,
		key, 
		iv);
	EVP_EncryptUpdate(ctx, // объект с настройками
		(unsigned char*)crypted_text, // входной параметр: ссылка, куда помещать зашифрованные данные
		&lenght, // выходной параметр: длина полученного шифра
		(unsigned char*)str, // входной параметр: что шифровать
		len); // входной параметр : длина входных данных
	crypted_len = lenght;
	EVP_EncryptFinal_ex(ctx, (unsigned char*)crypted_text, &lenght);
	crypted_len += lenght;
	len = crypted_len;
	EVP_CIPHER_CTX_free(ctx);
	delete[] str;
	str = nullptr;
	str = new char[len];
	//strcpy_s(str, len, crypted_text);
	for (int i = 0; i < len + 1; i++) {
		str[i] = crypted_text[i];
	}
	str[len] = '\0';
	delete[] crypted_text;
	crypted_text = nullptr;
	return 0;
}

int my_string::decrypto()
{
	char * decrypted_text = new char[len + len];
	int decrypted_len = 0;
	int lenght;
	unsigned char *key = (unsigned char *)"0123456789";
	unsigned char *iv = (unsigned char *)"0123456789012345";
	EVP_CIPHER_CTX *ctx;
	ctx = EVP_CIPHER_CTX_new();
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	EVP_DecryptUpdate(ctx, (unsigned char*)decrypted_text, &lenght, (unsigned char*)str, len);  // СОБСТВЕННО, ШИФРОВАНИЕ
	decrypted_len = lenght;
	EVP_DecryptFinal_ex(ctx, (unsigned char*)decrypted_text, &lenght);
	decrypted_len += lenght;
	len = decrypted_len;
	EVP_CIPHER_CTX_free(ctx);
	delete[] str;
	str = nullptr;
	str = new char[len+1];
	
	for (int i = 0; i < len; i++) {
		str[i] = decrypted_text[i];
	}
	str[len] = '\0';
	delete[] decrypted_text;
	decrypted_text = nullptr;
	return 0;
}

int my_string::find(char * find_str)
{
	int i;
	int result = -1;
	bool found = false;
	int lenght = strlen(find_str);
	for (i = 0; i < len; i++) {
		
		for (int j = 0; j < lenght; j++) {
			if (find_str[j] != str[i + j]) {
				found = false;
				break;
			}
			found = true;
		}
		if (found) {
			result = i;
			break;
		}
		
	}
	return result;
}

std::istream & operator>>(std::istream & is, my_string & input_arr)
{
	std::string temp;
	std::getline(is, temp);
	input_arr.len = temp.length();
	for (int i = 0; i < temp.length(); i++) {
		input_arr.str[i] = temp[i];
	}
	input_arr.str[temp.length()] = '\0';
	return is;
}

std::ostream & operator<<(std::ostream & os, my_string &input_arr)
{
	for (int i = 0; i < input_arr.lenght(); i++) {
		os << input_arr.at(i);
	}
	return os;
	
}
