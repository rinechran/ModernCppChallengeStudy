#include <gsl/gsl>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>

//1,1,3,5,8,13,3,5,8,8,5

int main() {
	std::vector<std::string> numberArr = {
		{"07555 123456"},
		{"07555123456"},
		{"+ 44 7555 123456"},
		{"44 7555 123456"},
		{"7555 123456"}
	};


	for (auto &i : numberArr) {
		std::string tmp;
		for (auto &j : i) {
			if (tmp.size() >= 2) {
				if (tmp == "44")std::cout << i << std::endl;
				break;
			}
			if (j != '+' && j != ' ') tmp += j;
		}

	}
}