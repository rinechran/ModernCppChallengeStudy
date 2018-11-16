#include <gsl/gsl>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <string>
#include <thread>
using namespace std;

namespace ch = std::chrono;



int main() {

	std::tm time{};
	time.tm_year = 2018- 1900;
	time.tm_mon = 12;
	time.tm_mday = 1;

	mktime(&(time));

	std::cout << time.tm_wday + 1;


	


}