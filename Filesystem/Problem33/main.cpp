#include <gsl/gsl>
#include <iostream>
#include <algorithm>
#include <regex>
#include <string>
#include <thread>
#include <vector>

using namespace std;

//cmd.exe 512 Running SYSTEM      48 64bit
struct Process {

	std::string name;
	uint32_t uid;
	enum STATUS { Running, Syspended };
	STATUS status;
	std::string user;
	uint32_t memorySize;
	int bit;
	
};
std::unordered_map<Process::STATUS, std::string> StatusToString{
	{Process::STATUS::Running,"Running"},
	{Process::STATUS::Syspended,"Syspended"}
};

std::string to_String(Process::STATUS status) {
	return StatusToString.find(status)->second;
}
int main() {
	std::vector<Process> process
	{
		{"chrome.exe"s,1044,Process::Running,"rinechran", 25180,32},
		{"test.exe"s,1044,Process::Running,"rinechran", 123213,32}

	};
	for (auto &i : process) {
		std::cout << i.name << "  " << i.uid << "  " << to_String(i.status)
			<< " " << i.user << " " << i.memorySize << " " << i.bit << std::endl;

	}
}