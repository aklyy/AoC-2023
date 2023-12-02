#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include "Day2.h"


constexpr int maxRed{ 12 };
constexpr int maxGreen{ 13 };
constexpr int maxBlue{ 14 };

std::regex rgxRed("\\b(\\d+)\\s[r][e][d]");
std::regex rgxGreen("\\b(\\d+)\\s[g][r][e][e][n]");
std::regex rgxBlue("\\b(\\d+)\\s[b][l][u][e]");

int checkGameID(std::string line) {
	std::string gameID;
	for (int i = 0; i < 9; i++) {
		if (line[i] == ':') break;
		if (isdigit(line[i])) {
			gameID += line[i];
		}
	}
	return stoi(gameID);
}


bool checkGame(std::string line) {

	
	std::sregex_iterator it(line.begin(), line.end(), rgxRed);
	std::sregex_iterator end;
	int limit{ 0 };
	while (it != end) {
		std::smatch match = *it;
		++it;
		limit = stoi(match[1].str());
		if (limit > maxRed) {
			return false;
		}
	}

	std::sregex_iterator it2(line.begin(), line.end(), rgxGreen);
	std::sregex_iterator end2;
	limit = 0;
	while (it2 != end2) {
		std::smatch match = *it2;
		++it2;
		limit = stoi(match[1].str());
		if (limit > maxGreen) {
			return false;
		}
	}

	std::sregex_iterator it3(line.begin(), line.end(), rgxBlue);
	std::sregex_iterator end3;
	limit = 0;
	while (it3 != end3) {
		std::smatch match = *it3;
		++it3;
		limit = stoi(match[1].str());
		if (limit > maxBlue) {
			return false;
		}
	}
	return true;
}


int checkGamePart2(std::string line) {


	std::sregex_iterator it(line.begin(), line.end(), rgxRed);
	std::sregex_iterator end;
	int limitRed{ 0 };
	while (it != end) {
		std::smatch match = *it;
		++it;
		if(stoi(match[1].str()) >= limitRed){
			limitRed = stoi(match[1].str());
		}
		
	}

	std::sregex_iterator it2(line.begin(), line.end(), rgxGreen);
	std::sregex_iterator end2;
	int limitGreen{ 0 };
	while (it2 != end2) {
		std::smatch match = *it2;
		++it2;
		if (stoi(match[1].str()) >= limitGreen) {
			limitGreen = stoi(match[1].str());
		}
	}

	std::sregex_iterator it3(line.begin(), line.end(), rgxBlue);
	std::sregex_iterator end3;
	int limitBlue = 0;
	while (it3 != end3) {
		std::smatch match = *it3;
		++it3;
		if (stoi(match[1].str()) >= limitBlue) {
			limitBlue = stoi(match[1].str());
		}
	}
	return limitBlue * limitGreen * limitRed;
}


void day2() {
	std::string line;
	std::ifstream file("input.txt");
	int counter{0};
	if (file.is_open()) {
		while (std::getline(file, line)) {
			if (checkGame(line) == true) {
				counter += checkGameID(line);
			}
		}
		file.close();
	}
	std::cout << counter << '\n';
	counter = 0;
	file.open("input.txt");
	if (file.is_open()) {
		while (std::getline(file, line)) {
			counter += checkGamePart2(line);
		}
		file.close();
	}
	std::cout << counter;
}