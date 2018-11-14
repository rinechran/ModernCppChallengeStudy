#include <gsl/gsl>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <string>



using namespace std;
class LogSystem {

public:
	LogSystem()  {
		fs.open("log.txt", ios::trunc | ios::out);
	
	}

	LogSystem& operator<<(std::string str) {
		fs << str;
		return *this;
	}
	
	std::fstream fs;
	
};
int main()
{
	int a;
	int c;
	int k;
	int arr[1000];


}