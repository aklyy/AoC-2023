#include <iostream>
#include <fstream>
#include <string>
#include "Day1.h"


int lookForNumbersPart1(std::string line) {
	int s{0};

	for (int i = 0; i < line.length(); i++) {
		if (isdigit(line[i])) {
			char firstNumber = line[i];

			for (int j = (line.length() - 1); j >= 0; j--) {

				if (isdigit(line[j])) {
					if (j > i) {
						char secondNumber = line[j];
						s = (static_cast<int>(firstNumber) - 48) * 10 + (static_cast<int>(secondNumber) - 48);
						return s;
					}
					else {
						s = (static_cast<int>(firstNumber) - 48) * 10 + (static_cast<int>(firstNumber) - 48);
						return s;
					}
				}
			}
		}
	}
}


std::string ReplaceAll(std::string original, std::string replaceThis, std::string replaceWith)
{
	std::string::size_type pos = 0;
	while ((pos = original.find(replaceThis, pos)) != std::string::npos)
	{
		original.replace(pos, (replaceThis.length()), replaceWith);
		pos += replaceWith.length();
	}
	return original;
}


int lookForNumbersPart2(std::string line) {
	line = ReplaceAll(line, "one", "on1e");
	line = ReplaceAll(line, "two", "tw2o");
	line = ReplaceAll(line, "three", "thre3e");
	line = ReplaceAll(line, "four", "fou4r");
	line = ReplaceAll(line, "five", "fiv5e");
	line = ReplaceAll(line, "six", "si6x");
	line = ReplaceAll(line, "seven", "sev7en");
	line = ReplaceAll(line, "eight", "eig8ht");
	line = ReplaceAll(line, "nine", "ni9ne");
	int s{ 0 };

	for (int i = 0; i < line.length(); i++) {
		if (isdigit(line[i])) {
			char firstNumber = line[i];

			for (int j = (line.length() - 1); j >= 0; j--) {

				if (isdigit(line[j])) {
					if (j > i) {
						char secondNumber = line[j];
						s = (static_cast<int>(firstNumber) - 48) * 10 + (static_cast<int>(secondNumber) - 48);
						return s;
					}
					else {
						s = (static_cast<int>(firstNumber) - 48) * 10 + (static_cast<int>(firstNumber) - 48);
						return s;
					}
				}
			}
		}
	}
}


void day1() {
	std::string line;
	std::ifstream file("input.txt");
	int counter{ 0 };
	
	if (file.is_open()) {
		while (std::getline(file, line)) {
			counter += lookForNumbersPart1(line);
		}
		std::cout << counter << '\n';
		file.close();
	}

	file.open("input.txt");
	if (file.is_open()) {
		counter = 0;
		while (std::getline(file, line)) {
			counter += lookForNumbersPart2(line);
		}
		std::cout << counter << '\n';
		file.close();
	}
}