
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

static int writer(char *data,
	size_t size,
	size_t nmemb,
	std::string *writerData)
{
	if (writerData == NULL)
		return 0;

	writerData->append(data, size*nmemb);

	return size * nmemb;
}
int get_HTML(std::string href, std::string &buffer) {
	CURL *curl = nullptr;
	CURLcode res;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, href.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		return 0;
	} 
	else
	{
		return -1;
	}
}
int find_in_HTML(std::string begin, std::string end, std::string &outbufffer, std::string &inbuffer) {
	int pos;
	pos = inbuffer.find(begin);
	if (pos != std::string::npos) {
		inbuffer.erase(0, pos + begin.length());
		pos = inbuffer.find(end);
		if (pos == std::string::npos) {
			return -1;
		}
		outbufffer = inbuffer.substr(0, pos);
		return 0;
	} 
	return -1;
}
struct team
{
	double total_points = 0;
	double percent_of_winning;
	std::string name;
	std::string teammates[5];
	
};
int main()
{
	std::string buffer, temp_buffer, link, temp_buffer2, change, best_player, atributes;
	std::string * mapsname = nullptr;
	team team1, team2;
	int total_maps;
	std::cout << "Write before link -wpo to turn off checking people's opinion.\n";
	std::cout << "Your link: ";
	std::cin >> link;
	std::cin >> atributes;
	get_HTML(link, buffer);
	std::cout << "||";

	//team1 place

	find_in_HTML("<div class=\"team1-gradient\"> <a href=\"", "\">", temp_buffer, buffer);
	temp_buffer = "https://www.hltv.org" + temp_buffer;
	get_HTML(temp_buffer, temp_buffer2);
	find_in_HTML("<span class=\"value\">#", "<", temp_buffer, temp_buffer2);
	team1.total_points += 100 - strtod(temp_buffer.c_str(), NULL);
	std::cout << "||";

	//team2 place

	find_in_HTML("<div class=\"team2-gradient\"> <a href=\"", "\">", temp_buffer, buffer);
	temp_buffer = "https://www.hltv.org" + temp_buffer;
	get_HTML(temp_buffer, temp_buffer2);
	find_in_HTML("<span class=\"value\">#", "<", temp_buffer, temp_buffer2);
	team2.total_points += 100 - strtod(temp_buffer.c_str(), NULL);
	std::cout << "||";

	//team's names

	find_in_HTML("<div class=\"teamName\">", "</div>", temp_buffer, buffer);
	team1.name = temp_buffer;
	find_in_HTML("<div class=\"teamName\">", "</div>", temp_buffer, buffer);
	team2.name = temp_buffer;
	std::cout << "||";

	find_in_HTML("<div class=\"padding preformatted-text\">", "</div>", temp_buffer, buffer);
	
	//checking count of maps

	if (temp_buffer.find("Best of 1") != std::string::npos) {
		total_maps = 1;
	}
	else if (temp_buffer.find("Best of 2") != std::string::npos) {
		total_maps = 2;
	}
	else if (temp_buffer.find("Best of 3") != std::string::npos) {
		total_maps = 3;
	}
	else if (temp_buffer.find("Best of 5") != std::string::npos) {
		total_maps = 5;
	}
	std::cout << "||";

	//check change

	if (temp_buffer.find("will play") != std::string::npos) {
		change = temp_buffer.substr(temp_buffer.find_last_of("* ") + 1, temp_buffer.find(" will play"));
	}
	std::cout << "||";

	//check picks

	find_in_HTML("<div class=\"mapname\">", "</div>", temp_buffer, buffer);
	if (temp_buffer != "TBA") {
		mapsname = new std::string[total_maps];
		mapsname[0] = temp_buffer;
		for (int i = 1; i < total_maps; i++) {
			find_in_HTML("<div class=\"mapname\">", "</div>", temp_buffer, buffer);
			mapsname[i] = temp_buffer;
		}
	}
	std::cout << "||";

	//got people's opinion
	if (atributes.find("-wpo") != std::string::npos) {
		find_in_HTML("<div class=\"percentage\">", "%</div>", temp_buffer, buffer);
		team1.total_points += strtod(temp_buffer.c_str(), NULL) / 10;
		find_in_HTML("<div class=\"percentage\">", "%</div>", temp_buffer, buffer);
		team2.total_points += strtod(temp_buffer.c_str(), NULL) / 10;
		std::cout << "||";
	}
	//team1 players stats

	for (int i = 0; i < 5; i++) {
		find_in_HTML("<td class=\"player\"><a href=\"", "\">", temp_buffer, buffer);
		team1.teammates[i] = temp_buffer.substr(temp_buffer.find_last_of("/") + 1, temp_buffer.length());
		temp_buffer = "https://www.hltv.org" + temp_buffer;
		get_HTML(temp_buffer, temp_buffer2);
		std::cout << "||";

		//stats before played maps

		for (int j = 0; j < 3; j++) {
			find_in_HTML("<span class=\"statsVal\">", "</span>", temp_buffer, temp_buffer2);
			if (temp_buffer.find("%") != std::string::npos) {
				temp_buffer = temp_buffer.substr(0, temp_buffer.find("%"));
				team1.total_points += strtod(temp_buffer.c_str(), NULL) / 10;
			}
			else {
				team1.total_points += std::strtod(temp_buffer.c_str(), NULL) * 10;
			}
		}
		
		//played maps

		find_in_HTML("<span class=\"statsVal\">", "</span>", temp_buffer, temp_buffer2);
		if (int(temp_buffer.c_str()) < 100) {
			team1.total_points -= strtod(temp_buffer.c_str(), NULL) / 10;
		}
		else {
			team1.total_points += strtod(temp_buffer.c_str(), NULL) / 10;
		}
		
		//stats after played maps

		for (int j = 0; j < 2; j++) {
			find_in_HTML("<span class=\"statsVal\">", "</span>", temp_buffer, temp_buffer2);
			if (temp_buffer.find("%") != std::string::npos) {
				temp_buffer = temp_buffer.substr(0, temp_buffer.find("%"));
				team1.total_points += strtod(temp_buffer.c_str(), NULL) / 10;
			}
			else {
				team1.total_points += std::strtod(temp_buffer.c_str(), NULL) * 10;
			}
		}
	}
	
	//team2

	for (int i = 0; i < 5; i++) {
		find_in_HTML("<td class=\"player\"><a href=\"", "\">", temp_buffer, buffer);
		team2.teammates[i] = temp_buffer.substr(temp_buffer.find_last_of("/")+1, temp_buffer.length());
		temp_buffer = "https://www.hltv.org" + temp_buffer;
		get_HTML(temp_buffer, temp_buffer2);
		std::cout << "||";

		//stats before played maps

		for (int j = 0; j < 3; j++) {
			find_in_HTML("<span class=\"statsVal\">", "</span>", temp_buffer, temp_buffer2);
			if (temp_buffer.find("%") != std::string::npos) {
				temp_buffer = temp_buffer.substr(0, temp_buffer.find("%"));
				team2.total_points += strtod(temp_buffer.c_str(), NULL) / 10;
			}
			else {
				team2.total_points += std::strtod(temp_buffer.c_str(), NULL) * 10;
			}
		}
		
		//played maps

		find_in_HTML("<span class=\"statsVal\">", "</span>", temp_buffer, temp_buffer2);
		if (int(temp_buffer.c_str()) < 100) {
			team2.total_points -= 10;
		}
		else {
			team2.total_points += strtod(temp_buffer.c_str(), NULL) / 10;
		}
		
		//stats after played maps

		for (int j = 0; j < 2; j++) {
			find_in_HTML("<span class=\"statsVal\">", "</span>", temp_buffer, temp_buffer2);
			if (temp_buffer.find("%") != std::string::npos) {
				temp_buffer = temp_buffer.substr(0, temp_buffer.find("%"));
				team2.total_points += strtod(temp_buffer.c_str(), NULL) / 10;
			}
			else {
				team2.total_points += std::strtod(temp_buffer.c_str(), NULL) * 10;
			}
		}
	}
	
	//check best player

	find_in_HTML("<span class=\"player-nick\">", "</span>", temp_buffer, buffer);
	best_player = temp_buffer;
	for (int i = 0; i < 5; i++) {
		if (!change.empty()) {
			if (change == team1.teammates[i]) {
				team1.total_points -= team1.total_points/10;
				continue;
			}
		}
		if (best_player == team1.teammates[i]) {
			team1.total_points += 10;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (!change.empty()) {
			if (change == team2.teammates[i]) {
				team2.total_points -= team2.total_points/10;
				continue;
			}
		}
		if (best_player == team2.teammates[i]) {
			team2.total_points += 10;
		}
	}
	std::cout << "||";

	//checking chance of winning on maps

	if (buffer.find("<div class=\"map-stats-infobox-maps-played\">") != std::string::npos) {
		
		//if maps picked

		if (mapsname != nullptr) {
			for (int i = 0; i < total_maps; i++) {
				
				//team1 points

				find_in_HTML("class=\"a-reset\">", "</a>", temp_buffer, buffer);
				if (temp_buffer != "-") { //if there is percent of winning
					temp_buffer = temp_buffer.substr(0, temp_buffer.find("%"));
					find_in_HTML("<div class=\"map-stats-infobox-maps-played\">", " maps</div>", temp_buffer2, buffer);
					if (strtod(temp_buffer2.c_str(), NULL) > 99) {
						team1.total_points += (strtod(temp_buffer2.c_str(), NULL) / (100 - strtod(temp_buffer.c_str(), NULL))) * 10;
					}
					else {
						team1.total_points += (strtod(temp_buffer.c_str(), NULL) / (100.0 - strtod(temp_buffer2.c_str(), NULL))) * 10;
					}
				}
				else { // if there is no persent of winning
					team1.total_points -= 5;
				}
				
				//team2 points

				find_in_HTML("class=\"a-reset\">", "</a>", temp_buffer, buffer);
				if (temp_buffer != "-") {//if there is percent of winning
					temp_buffer = temp_buffer.substr(0, temp_buffer.find("%"));
					find_in_HTML("<div class=\"map-stats-infobox-maps-played\">", " maps</div>", temp_buffer2, buffer);
					if (strtod(temp_buffer2.c_str(), NULL) > 99) {
						team2.total_points += (strtod(temp_buffer2.c_str(), NULL) / (100 - strtod(temp_buffer.c_str(), NULL))) * 10;
					}
					else {
						team2.total_points += (strtod(temp_buffer.c_str(), NULL) / (100.0 - strtod(temp_buffer2.c_str(), NULL))) * 10;
					}
				}
				else {
					team2.total_points -= 5;
				}
			}
		}
		else {
			
			//if maps not picked

			for (int i = 0; i < 7; i++) {
				//team1 stats
				find_in_HTML("class=\"a-reset\">", "</a>", temp_buffer, buffer);
				if (temp_buffer != "-") {//if there is percent of winning
					temp_buffer = temp_buffer.substr(0, temp_buffer.find("%"));
					find_in_HTML("<div class=\"map-stats-infobox-maps-played\">", " maps</div>", temp_buffer2, buffer);
					//team1.total_points += (strtod(temp_buffer.c_str(), NULL) / 100) * strtod(temp_buffer2.c_str(), NULL);
					if (strtod(temp_buffer2.c_str(), NULL) > 99) {
						team1.total_points += (strtod(temp_buffer2.c_str(), NULL) / (100 - strtod(temp_buffer.c_str(), NULL))) * 10;
					}
					else {
						team1.total_points += (strtod(temp_buffer.c_str(), NULL) / (100.0 - strtod(temp_buffer2.c_str(), NULL))) * 10;
					}
				}
				else {//if there is no percent of winning
					team1.total_points -= 5;
				}
				
				//team2 stats

				find_in_HTML("class=\"a-reset\">", "</a>", temp_buffer, buffer);
				if (temp_buffer != "-") {//if there is percent of winning
					temp_buffer = temp_buffer.substr(0, temp_buffer.find("%"));
					find_in_HTML("<div class=\"map-stats-infobox-maps-played\">", " maps</div>", temp_buffer2, buffer);
					if (strtod(temp_buffer2.c_str(), NULL) > 99) { //check count of maps
						team2.total_points += (strtod(temp_buffer2.c_str(), NULL) / (100 - strtod(temp_buffer.c_str(), NULL))) * 10;
					}
					else {
						team2.total_points += (strtod(temp_buffer.c_str(), NULL) / (100.0 - strtod(temp_buffer2.c_str(), NULL))) * 10;
					}
				}
				else {//if there is no percent of winning
					team2.total_points -= 5;
				}
			}
		}
	}
	std::cout << "||";

	//last matches team1

	bool first_team = true;
	std::string name1, name2, count1, count2;
	int total_maps2;
	while (buffer.find("<div class=\"half-width standard-box\">") != std::string::npos) {
		if (buffer.find("<div class=\"half-width standard-box\">") == std::string::npos) {
			first_team = false;
			break;
		}
		find_in_HTML("<td><a href=\"", "\">", temp_buffer, buffer);
		temp_buffer = "https://www.hltv.org" + temp_buffer;
		get_HTML(temp_buffer, temp_buffer2);
		find_in_HTML("<div class=\"teamName\">", "</div>", name1, temp_buffer2);
		//find_in_HTML("<div class=\"teamName\">", "</div>", name2, temp_buffer2);
		find_in_HTML("<div class=\"padding preformatted-text\">", "</div>", temp_buffer, temp_buffer2);
		if (temp_buffer.find("Best of 1") != std::string::npos) {
			total_maps2 = 1;
		}
		else if (temp_buffer.find("Best of 2") != std::string::npos) {
			total_maps2 = 2;
		}
		else if (temp_buffer.find("Best of 3") != std::string::npos) {
			total_maps2 = 3;
		}
		else if (temp_buffer.find("Best of 5") != std::string::npos) {
			total_maps2 = 5;
		}
		std::cout << "||";
		for (int i = 0; i < total_maps; i++) {
			find_in_HTML("<div class=\"results\"><span class=\"", "/span>", temp_buffer, temp_buffer2);
			find_in_HTML("\">", "<", count1, temp_buffer);
			find_in_HTML("<span class=\"\">:</span><span class=\"", "/span>", temp_buffer, temp_buffer2);
			find_in_HTML("\">", "<", count2, temp_buffer);
			if (name1 == team1.name) {
				team1.total_points += (strtod(count1.c_str(), NULL) - strtod(count2.c_str(), NULL));
			}
			else {
				team1.total_points += (strtod(count2.c_str(), NULL) - strtod(count1.c_str(), NULL));
			}

		}
		std::cout << "||";
	}
	std::cout << "||";

	//last matches team2

	while (buffer.find("<td><a href=\"") != std::string::npos) {
		find_in_HTML("<td><a href=\"", "\">", temp_buffer, buffer);
		temp_buffer = "https://www.hltv.org" + temp_buffer;
		get_HTML(temp_buffer, temp_buffer2);
		find_in_HTML("<div class=\"teamName\">", "</div>", name1, temp_buffer2);
		//find_in_HTML("<div class=\"teamName\">", "</div>", name2, temp_buffer2);
		find_in_HTML("<div class=\"padding preformatted-text\">", "</div>", temp_buffer, temp_buffer2);
		if (temp_buffer.find("Best of 1") != std::string::npos) {
			total_maps2 = 1;
		}
		else if (temp_buffer.find("Best of 2") != std::string::npos) {
			total_maps2 = 2;
		}
		else if (temp_buffer.find("Best of 3") != std::string::npos) {
			total_maps2 = 3;
		}
		else if (temp_buffer.find("Best of 5") != std::string::npos) {
			total_maps2 = 5;
		}
		std::cout << "||";
		for (int i = 0; i < total_maps; i++) {
			find_in_HTML("<div class=\"results\"><span class=\"", "/span>", temp_buffer, temp_buffer2);
			find_in_HTML("\">", "<", count1, temp_buffer);
			find_in_HTML("<span class=\"\">:</span><span class=\"", "/span>", temp_buffer, temp_buffer2);
			find_in_HTML("\">", "<", count2, temp_buffer);
			if (name1 == team1.name) {
				team2.total_points += (strtod(count1.c_str(), NULL) - strtod(count2.c_str(), NULL));
			}
			else {
				team2.total_points += (strtod(count2.c_str(), NULL) - strtod(count1.c_str(), NULL));
			}

		}
		std::cout << "||";
	}
	std::cout << "||";

	//played matches 
	while (buffer.find("<td class=\"date\"><a href=\"") != std::string::npos) {
		find_in_HTML("<td class=\"result\"><span class=\"", "/span>", temp_buffer, buffer);
		find_in_HTML("\">", "<", count1, temp_buffer);
		find_in_HTML("<td class=\"result\"><span class=\"", "/span>", temp_buffer, buffer);
		find_in_HTML("\">", "<", count2, temp_buffer);
		team1.total_points += (strtod(count1.c_str(), NULL) - strtod(count2.c_str(), NULL));
		team2.total_points += (strtod(count2.c_str(), NULL) - strtod(count1.c_str(), NULL));
		std::cout << "||";
	}

	double total_points = team1.total_points + team2.total_points;
	team1.percent_of_winning = (team1.total_points / total_points) * 100;
	team2.percent_of_winning = 100 - team1.percent_of_winning;
	std::cout << "||" << std::endl;
	std::cout << team1.name << "\t\t" << team2.name << std::endl;
	std::cout << team1.percent_of_winning << "%" << "\t\t" << team2.percent_of_winning << "%";
}


