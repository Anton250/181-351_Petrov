#pragma once
#include<iostream>
#include<string>
#include <openssl/conf.h> // �������, ��������� � ��������� ��������� OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // ���� ���������������� ������� https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // ���� ���������� ������ OpenSSL � �� �����������
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
	my_string(char* arr); //����������� ����������� char* � ������ ������
	my_string(std::string arr);//����������� ����������� std::string � ������ ������
	my_string(my_string &arr);//����������� ����������� ������ �� ������ � ������ ������
	~my_string();
	void clear(); //������� �������
	void add(char* arr); //���������� ������ char* � ����� �������
	void add(std::string arr); //���������� ������ std::string � ����� �������
	int insert(int pos, char* arr); //���������� ������ char* �� ������������ �������
	int insert(int pos, std::string arr);//���������� ������ std::string �� ������������ �������
	int cut(int pos, int count);//�������� �������� ����� ������� � �������� ����� 
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

