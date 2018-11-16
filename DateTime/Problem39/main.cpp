#include <gsl/gsl>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <string>
#include <thread>
using namespace std;

namespace ch = std::chrono;


template <class M, class T>
M fnDuration(T &fn) {
	ch::system_clock::time_point start = ch::system_clock::now();
	fn();
	ch::system_clock::time_point end = ch::system_clock::now();

	return ch::duration_cast<M>(end - start);

}



void fn() {
	std::this_thread::sleep_for(10s);
}

int main() {

	auto i = fnDuration<std::chrono::seconds>(fn);
	std::cout << i.count();
}