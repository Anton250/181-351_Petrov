
#define _CRT_SECURE_NO_WARNINGS
#define CURL_STATICLIB 
//#pragma comment(lib, "C:/Program Files (x86)/GnuWin32/lib/libpng.lib")
#include "curl/curl.h" 
#include <stdio.h> 
#include <string> 
#include <iostream> 
#include <vector>
#include <stack>
#include <openssl/conf.h> // функции, структуры и константы настройки OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // сами криптогрфические функции https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // коды внутренних ошибок OpenSSL и их расшифровка
#include <openssl/aes.h>
#include <fstream>
#include <opencv2\opencv.hpp> 
#include <opencv2\imgproc\types_c.h>
#include <opencv2\imgcodecs.hpp>
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\objdetect.hpp>

#ifdef _WIN64 
#pragma comment (lib, "Normaliz.lib") 
#pragma comment (lib, "Ws2_32.lib") 
#pragma comment (lib, "Wldap32.lib") 
#pragma comment (lib, "Crypt32.lib") 
#pragma comment (lib, "advapi32.lib") 
#elif _WIN32 
#pragma comment (lib, "Normaliz.lib") 
#pragma comment (lib, "Ws2_32.lib") 
#pragma comment (lib, "Wldap32.lib") 
#pragma comment (lib, "Crypt32.lib") 
#pragma comment (lib, "advapi32.lib") 
#endif 

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")

static size_t writer(char *ptr,
	size_t size,
	size_t nmemb,
	void *userdata)
{	
	FILE *data = (FILE*)userdata;
	if (data == NULL)
		return 0;
	size_t written = fwrite(ptr, size, nmemb, data);
	return written;
}
static int url_writer(char *data,
	size_t size,
	size_t nmemb,
	std::string *writerData)
{
	if (writerData == NULL)
		return 0;

	writerData->append(data, size*nmemb);

	return size * nmemb;
}

int main()
{
	std::fstream url_file;
	char url[256];
	unsigned char plaintext[1024];
	unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
	unsigned char cryptedtext[1024]; // зашифрованный результат
	std::cin.getline(url, 256);
	CURL *curl = nullptr;
	CURL *curl_img = nullptr;
	std::string buffer, img_url, img_name, check;
	FILE *out = fopen("Encrypted_url.txt", "wb");
	url_file.open("Text_from_url.txt", std::ios::out);
	CURLcode res;
	curl = curl_easy_init();
	std::stack<std::string> name_of_files;
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, url_writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
		res = curl_easy_perform(curl);
		if (res != CURLE_OK) {
			std::cout << "curl_easy_perform() failed: %s\n" << curl_easy_strerror(res) << std::endl;
			return 0;
		}
		curl_easy_cleanup(curl);
	}
	
	int pos = 0;
	int check_pos = 0;
	FILE *img;
	while (pos != std::string::npos) {
		pos = buffer.find("<img ", 0);
		if (pos == std::string::npos) {
			break;
		}
		buffer.erase(0, pos + 5);
		pos = buffer.find("src=\"", 0);
		buffer.erase(0, pos + 5);
		pos = buffer.find("\"", 0);
		img_url = buffer.substr(0, pos);
		pos = img_url.find_last_of("/");
		img_name = img_url.substr(pos + 1);
		pos = img_name.find_last_of(".");
		if ((pos != std::string::npos) &&(img_name.substr(pos) == ".png" || img_name.substr(pos) == ".jpg")) {
			//img_name = img_name.substr(0, pos);
			//img_name += ".jpg";
		}
		else {
			continue;
		}
		/*pos = buffer.find(">", 0);
		check = check.substr(0, pos);
		check_pos = check.find("width=\"", 0);
		if (check_pos != std::string::npos) {
			check.erase(0, pos + 7);
			check_pos = buffer.find("\"", 0);
			check = check.substr(0, check_pos);
			if (std::stoi(check) < 150) {
				continue;
			}
		}*/
		img = fopen(img_name.c_str(), "wb");
		//strcpy_s(img_url_char, 128, img_url.c_str());
		curl_img = curl_easy_init();
		if (curl_img) {
			curl_easy_setopt(curl_img, CURLOPT_URL, img_url.c_str());
			//curl_easy_setopt(curl_img, CURLOPT_HEADER, 0);
			curl_easy_setopt(curl_img, CURLOPT_FOLLOWLOCATION, 1);
			curl_easy_setopt(curl_img, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36");
			curl_easy_setopt(curl_img, CURLOPT_WRITEFUNCTION, writer);
			curl_easy_setopt(curl_img, CURLOPT_WRITEDATA, img);
			res = curl_easy_perform(curl_img);
			if (res != CURLE_OK) {
				std::cout << "Failed to download " << img_name << std::endl;
				curl_easy_cleanup(curl_img);
				curl_img = nullptr;
				continue;
			}
			
			curl_easy_cleanup(curl_img);
			curl_img = nullptr;
		}
		fclose(img);
		std::cout << "Download " << img_name << " successfull!" << '\n';
		//name_of_files.push(img_name);
		cv::CascadeClassifier face_cascade;
		cv::Mat image = cv::imread(img_name.c_str());
		cv::Mat groupFaces = cv::Mat(image.rows, image.cols, CV_8UC4);
		cv::cvtColor(image, groupFaces, cv::COLOR_RGB2BGRA);
		//cv::winrt_initContainer(cvContainer);
		//cv::imshow(std::string("Window 1"), groupFaces);
		if (!face_cascade.load("haarcascade_frontalface_alt.xml")) {
			std::cout << "Couldn't load face detector" << std::endl;
		}
		std::vector<cv::Rect> facesColl;
		cv::Mat frame_gray;

		cvtColor(groupFaces, frame_gray, cv::COLOR_BGR2GRAY);
		cv::equalizeHist(frame_gray, frame_gray);

		// Detect faces
		face_cascade.detectMultiScale(frame_gray,
			facesColl,
			1.1, 2,
			0 | cv::CASCADE_SCALE_IMAGE,
			cv::Size(1, 1));
		if (!facesColl.empty()) {
			url_file << "IMAGE NAME:   " << img_name << "    IMAGE URL:  " << img_url;
			url_file << '\n';
			std::cout << "Faces detected! In " << img_name << '\n';
			//img = fopen(img_name.c_str(), "rb");
		/*	plaintext = (unsigned char *)img_url.c_str();
			int plaintext_len = strlen((char *)plaintext);
			//std::ofstream fs("Encrypted_url.txt", std::ofstream::binary);
			std::cout << "Faces detected! In " << img_name <<  " Encrypting in \"Encrypted_url.txt\"..." << '\n';
			EVP_CIPHER_CTX *ctx;
			ctx = EVP_CIPHER_CTX_new();
			EVP_EncryptInit_ex(ctx, // ссылка на объект/структуру, куда заносятся параметры
				EVP_aes_256_cbc(), // ссылка на шифрующее ядро AES 256 (функцию с алгоритмом)
				NULL,
				key, // ключ/пароль/секрет
				iv);
			
			int len;
			for (int i = 0;i < strlen((char *)plaintext)/1024 + 1;i++) {
				plaintext_len = strlen((char *)plaintext);

				EVP_EncryptUpdate(ctx, // объект с настройками
					cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
					&len, // выходной параметр: длина полученного шифра
					plaintext, // входной параметр: что шифровать
					plaintext_len); // входной параметр : длина входных данных
				//int cryptedtext_len = len;
				fwrite(cryptedtext, 1, len, out);
			}
			//fs << cryptedtext;
			EVP_EncryptFinal_ex(ctx, cryptedtext, &len);
			fwrite(cryptedtext, 1, len, out);
			//fs << cryptedtext;
			EVP_CIPHER_CTX_free(ctx);
			std::cout << "Encrypting succesfull!" << "\n\n";
			/*for (unsigned int i = 0; i < facesColl.size(); i++)
			{
				auto face = facesColl[i];
				cv::rectangle(groupFaces, face, cv::Scalar(255, 255, 0), 3);
			}

			//cv::imshow(std::string("Window 2"), groupFaces);
			//cv::waitKey();
			*/
		}
		else {
			std::cout << "No faces detected. In " << img_name << "\n\n";
		}
		//fclose(img);
	}
	url_file.close();
	FILE *raw_url;
	raw_url = fopen("Text_from_url.txt", "rb");
	
	//std::ofstream fs("Encrypted_url.txt", std::ofstream::binary);
	std::cout << "Encrypting in \"Encrypted_url.txt\"..." << '\n';
	EVP_CIPHER_CTX *ctx;
	ctx = EVP_CIPHER_CTX_new();
	EVP_EncryptInit_ex(ctx, // ссылка на объект/структуру, куда заносятся параметры
		EVP_aes_256_cbc(), // ссылка на шифрующее ядро AES 256 (функцию с алгоритмом)
		NULL,
		key, // ключ/пароль/секрет
		iv);

	int len;
	//int plaintext_len;
	for (;;) {
		int plaintext_len = fread(plaintext, 1, 1024, raw_url);
		if (plaintext_len <= 0) break;
		EVP_EncryptUpdate(ctx, // объект с настройками
			cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
			&len, // выходной параметр: длина полученного шифра
			plaintext, // входной параметр: что шифровать
			plaintext_len); // входной параметр : длина входных данных
		//int cryptedtext_len = len;
		fwrite(cryptedtext, 1, len, out);
	}
	//fs << cryptedtext;
	EVP_EncryptFinal_ex(ctx, cryptedtext, &len);
	fwrite(cryptedtext, 1, len, out);
	//fs << cryptedtext;
	EVP_CIPHER_CTX_free(ctx);
	std::cout << "Encrypting succesfull! Deleting temporary files..." << "\n\n";
	fclose(out);
	fclose(raw_url);
	//raw_url = fopen("Text_from_url.txt", "wb");
	//fclose(raw_url);
	url_file.open("Text_from_url.txt", std::ios::out);
	url_file << "Data cleared.";
	url_file.close();
	std::cout << "Delete succesfull!" << '\n';
/*	int k = name_of_files.size();
	for (int i = 0; i < k; i++) {
		img_name = name_of_files.top();
		name_of_files.pop();
		cv::CascadeClassifier face_cascade;
		cv::Mat image = cv::imread(img_name.c_str());
		cv::Mat groupFaces = cv::Mat(image.rows, image.cols, CV_8UC4);
		cv::cvtColor(image, groupFaces, cv::COLOR_RGB2BGRA);
		//cv::winrt_initContainer(cvContainer);
		//cv::imshow(std::string("Window 1"), groupFaces);
		if (!face_cascade.load("haarcascade_frontalface_alt.xml")) {
			std::cout << "Couldn't load face detector" << std::endl;
		}
		std::vector<cv::Rect> facesColl;
		cv::Mat frame_gray;

		cvtColor(groupFaces, frame_gray, cv::COLOR_BGR2GRAY);
		cv::equalizeHist(frame_gray, frame_gray);

		// Detect faces
		face_cascade.detectMultiScale(frame_gray,
			facesColl,
			1.1, 2,
			0 | cv::CASCADE_SCALE_IMAGE,
			cv::Size(1, 1));
		if (!facesColl.empty()) {
			plaintext = (unsigned char *)img_url.c_str();
			int plaintext_len = strlen((char *)plaintext);
			//std::ofstream fs("Encrypted_url.txt", std::ofstream::binary);
			std::cout << "Faces detected! In " << img_name << " Encrypting in \"Encrypted_url.txt\"..." << '\n';
			EVP_CIPHER_CTX *ctx;
			ctx = EVP_CIPHER_CTX_new();
			EVP_EncryptInit_ex(ctx, // ссылка на объект/структуру, куда заносятся параметры
				EVP_aes_256_cbc(), // ссылка на шифрующее ядро AES 256 (функцию с алгоритмом)
				NULL,
				key, // ключ/пароль/секрет
				iv);
			plaintext_len = strlen((char *)plaintext);
			int len;
			EVP_EncryptUpdate(ctx, // объект с настройками
				cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
				&len, // выходной параметр: длина полученного шифра
				plaintext, // входной параметр: что шифровать
				plaintext_len); // входной параметр : длина входных данных
			int cryptedtext_len = len;
			fwrite(cryptedtext, 1, len, out);
			//fs << cryptedtext;
			EVP_EncryptFinal_ex(ctx, cryptedtext, &len);
			fwrite(cryptedtext, 1, len, out);
			//fs << cryptedtext;
			cryptedtext_len += len;
			EVP_CIPHER_CTX_free(ctx);
			std::cout << "Encrypting succesfull!" << "\n";
			/*for (unsigned int i = 0; i < facesColl.size(); i++)
			{
				auto face = facesColl[i];
				cv::rectangle(groupFaces, face, cv::Scalar(255, 255, 0), 3);
			}

			//cv::imshow(std::string("Window 2"), groupFaces);
			//cv::waitKey();
		}
		else {
			std::cout << "No faces detected. In " << img_name << "\n";
		}
	}*/
}

