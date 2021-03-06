
#define _CRT_SECURE_NO_WARNINGS
#define CURL_STATICLIB 

#include "curl/curl.h" 
#include <stdio.h> 
#include <string> 
#include <iostream> 

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

int main()
{
	FILE *img = fopen("img.png", "wb");
	CURL *curl_img = nullptr;
	CURLcode res;
	curl_img = curl_easy_init();
	if (curl_img) {
		curl_easy_setopt(curl_img, CURLOPT_URL, "http://27sysday.ru/wp-content/uploads/2018/05/android.png");
		curl_easy_setopt(curl_img, CURLOPT_HEADER, 0);
		curl_easy_setopt(curl_img, CURLOPT_FOLLOWLOCATION, 1);
		curl_easy_setopt(curl_img, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36");
		curl_easy_setopt(curl_img, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curl_img, CURLOPT_WRITEDATA, img);
		res = curl_easy_perform(curl_img);
		if (res != CURLE_OK) {
			std::cout << "curl_easy_perform() failed: %s\n" << curl_easy_strerror(res) << std::endl;
			return 0;
		}

		curl_easy_cleanup(curl_img);
	}
}

