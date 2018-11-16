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
	
	std::tm time[2]{};
	std::time_t time_t[2];
	time[0].tm_year = 2018- 1900;
	time[0].tm_mon = 12;
	time[0].tm_mday = 1;

	time[1].tm_year = 2018-1900;
	time[1].tm_mon = 12;
	time[1].tm_mday = 20;;
	time_t[0] = mktime(&(time[0]));
	time_t[1] = mktime(&(time[1]));

	auto i = difftime(time_t[1], time_t[0]);
	std::cout << i/(3600*24);

	


}