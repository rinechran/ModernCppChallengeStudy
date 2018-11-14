#include <gsl/gsl>
#include <iostream>
#include <algorithm>
#include <regex>
#include <string>
#include <thread>
#include <vector>



int main() {
	int arr[10][14]{};
	arr[0][13] = 1;
	for (int i = 1; i < 10; ++i) {
		for (int j = 1; j < 14; ++j) {
			arr[i][j] = arr[i-1][j ] + arr[i-1][j + 1];
		}
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 14; ++j) {
			if (arr[i][j])
				std::cout << arr[i][j];
			std::cout << " ";
		}
		std::cout << std::endl;
	}

	
}