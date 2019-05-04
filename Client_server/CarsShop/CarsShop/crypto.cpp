#include "crypto.h"



crypto::crypto()
{
}


crypto::~crypto()
{
}

QByteArray crypto::encrypt(QByteArray message)
{
	//unsigned char plaintext[1024];
	/*char cryptedtext[1024]; 
	//char text[1024];
	EVP_CIPHER_CTX *ctx;
	ctx = EVP_CIPHER_CTX_new();
	EVP_EncryptInit_ex(ctx, // ссылка на объект/структуру, куда заносятся параметры
		EVP_aes_256_cbc(), // ссылка на шифрующее ядро AES 256 (функцию с алгоритмом)
		NULL,
		key, // ключ/пароль/секрет
		iv); // рандомайзер (случайный начальный вектор)
	int len = 0;
	int crypt_len = 0;
	
	//strcpy_s(text, message.data());
	int plaintext_len = strlen(message.data());
		EVP_EncryptUpdate(ctx, // объект с настройками
			(unsigned char*)cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
			&len, // выходной параметр: длина полученного шифра
			(unsigned char*)message.constData(), // входной параметр: что шифровать
			plaintext_len); // входной параметр : длина входных данных
		crypt_len = len;
		
	
	// 5. Финализация процесса шифрования
	// необходима, если последний блок заполнен данными не полностью

	EVP_EncryptFinal_ex(ctx, (unsigned char*)cryptedtext, &len);
	crypt_len += len;
	/*str_mes.clear();
	str_mes.append(cryptedtext);*/
	
	//arr.append(cryptedtext, crypt_len);
	
	//cryptedtext_len += len;

	// 6. Удаление структуры
	//EVP_CIPHER_CTX_free(ctx);
	QByteArray arr;
	TinyAES aes;
	arr = aes.Encrypt(message, password);

	return arr;
}

QByteArray crypto::decrypt(QByteArray message)
{
	/*char plaintext[1024];
	char decryptedtext[1024]; 
	EVP_CIPHER_CTX *ctx;
	ctx = EVP_CIPHER_CTX_new();
	int len;
	int decrypt_len;
	
	//strcpy_s(plaintext, message.data());
	int cryptedtext_len = strlen(message.data());

	
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); 
	
	
	
		
	EVP_DecryptUpdate(ctx, (unsigned char* )decryptedtext, &len, (unsigned char*)message.constData(), cryptedtext_len);  // СОБСТВЕННО, ШИФРОВАНИЕ
	decrypt_len = len;
		

	
	// 4.

	EVP_DecryptFinal_ex(ctx, (unsigned char*)decryptedtext, &len);
	decrypt_len += len;
	
	/*str_mes.clear();
	str_mes.append(decryptedtext);
	message = QString::fromStdString(str_mes);*/
	
	//arr.append(decryptedtext, decrypt_len);
	// 5.
	
	//EVP_CIPHER_CTX_free(ctx);
	QByteArray arr;
	TinyAES aes;
	arr = aes.Decrypt(message, password);

	return arr;
}
