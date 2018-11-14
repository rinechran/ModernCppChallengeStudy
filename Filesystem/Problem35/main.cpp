#include <gsl/gsl>
#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
	uintmax_t size{};
	for (auto& p : fs::recursive_directory_iterator("D:\BattleNet")) {
		size+=p.file_size();
	}
	std::cout << size << std::endl;
}