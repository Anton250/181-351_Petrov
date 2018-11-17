#pragma once
class encrypt_with_many_keys
{
private:
	std::string user_text_str, key_str;
	char * key;
	int number_of_keys, i, j, lenght_for_one_key, limit, otherwise, number_of_char,
		number_of_key_char, char_for_array, shift_number;
	int k = 0;
	int count_of_char = 0;
	long key_lenght;
	long lenght;
	char * user_text_array;
	std::fstream user_file, keys_file;
	void cycle_for_encrypt(char * user_text_array, int limit, char * key, int number_of_char, int * k);

	void cycle_for_decode(char * user_text_array, int limit, char * key, int number_of_char, int * k);

	void get_str_to_array(std::string user_text_str);

	int count_of_char_in_file(std::fstream & file_name);

	int count_of_rows(std::fstream & file_name);
public:
	encrypt_with_many_keys();
	~encrypt_with_many_keys();
	std::fstream end_file;

	void print(char * user_text_array);

	void encryption(char * user_text_array);

	void decode(std::string user_text_str);

	void getString();

	void cycle_file_encryption(char * user_text_array);

	void cycle_file_decode(char * user_text_array);

	void openUserFile();

	void openDestanationFile();

	void openKeysFile();

	void encrypt_for_file();

	void decode_for_file();
};

