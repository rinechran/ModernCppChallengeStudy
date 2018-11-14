#include <gsl/gsl>
#include <iostream>
#include <algorithm>
#include <regex>
#include <string>
#include <thread>
#include <vector>
#include <fstream>


int main() {
	std::fstream fsRead("in.txt", std::ios::beg | std::ios::in);
	std::fstream fsWrite("out.txt", std::ios::beg | std::ios::out|std::ios::trunc);

	
	char ch[1000];
	while (!fsRead.eof()) {
		fsRead.getline(ch, 1000);
		if (ch[0] == '\0')
			continue;
		fsWrite << ch << std::endl;

	}

}