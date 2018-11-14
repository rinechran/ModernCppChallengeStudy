#include <gsl/gsl>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <string>
namespace fs = std::filesystem;

using namespace std;
int main()
{

	std::chrono::steady_clock::time_point time = chrono::steady_clock::now() - 10000000min;
	auto it = time.time_since_epoch();


	for (auto& p : fs::recursive_directory_iterator("D:\BattleNet")) {
		auto ftime = fs::last_write_time(p);

		auto dis = ftime.time_since_epoch();
		if (std::chrono::duration_cast<std::chrono::seconds>(dis - it).count() < 0) {
			std::cout << p.path() << '\n';

		}
	}

}