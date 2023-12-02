#include <iostream>
#include "Day1/Day1.h"
#include "Day2/Day2.h"


int main() {
	char day{};
	std::cout << "Pick the day: " << '\n';
	std::cin >> day;
	switch (day) {
	case '1':
		std::cout << day1();
	case '2':
		std::cout << day2();
	}
		
	return 0;
}