#pragma once
#include<iostream>
#include<string>
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
class my_string
{
private:
	char* str = nullptr;
	int len;
public:
	my_string();
	my_string(char* arr); //Конструктор копирования char* в объект класса
	my_string(std::string arr);//Конструктор копирования std::string в объект класса
	my_string(my_string &arr);//Конструктор копирования такого же класса в объект класса
	~my_string();
	void clear(); //Очистка массива
	void add(char* arr); //Добавление строки char* в конец массива
	void add(std::string arr); //Добавление строки std::string в конец массива
	int insert(int pos, char* arr); //Добавление строки char* на определенную позицию
	int insert(int pos, std::string arr);//Добавление строки std::string на определенную позицию
	int cut(int pos, int count);//Удаление заданной части массива с заднного места 
	friend my_string operator +(my_string & arr1, my_string arr2);
	int lenght();
	friend std::istream & operator >>(std::istream & is, my_string &input_arr);
	friend std::ostream & operator <<(std::ostream & os, my_string & input_arr);
	void array_equalization(char * first_array, char * second_array);
	void cat_str(char* dest, int len, char* source);
	char at(int i);
	int crypto();
	int decrypto();
	int find (char * find_str);
};

