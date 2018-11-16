#include <gsl/gsl>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <string>


namespace fs = std::filesystem;


using namespace std;
class LogSystem {
	static string FOLDER_NAME;
	static string FILE_NAME;

public:
	LogSystem()  {
		fs.open(FILE_NAME, ios::trunc | ios::out);
	}

	LogSystem& operator<<(std::string str) {
		fs << str;
		return *this;
	}
	void mkdir() {
		if (!fs::is_directory(FOLDER_NAME))
			fs::create_directory(FOLDER_NAME);
	}
	void copy() {
		auto i = std::chrono::system_clock::now();
		auto j = i.time_since_epoch();
		std::string toFileNmae = std::to_string(j.count()) + FILE_NAME;
		if (fs::exists(FILE_NAME))
			fs::copy(FILE_NAME, FOLDER_NAME + "/" + toFileNmae);

	}
	~LogSystem() {
		mkdir();
		fs.close();
		copy();
	}
	std::fstream fs;
	
};
string LogSystem::FOLDER_NAME = "log";
string LogSystem::FILE_NAME = "log.txt";


int main()
{
	LogSystem logsystem;
	logsystem << "hello world";

}