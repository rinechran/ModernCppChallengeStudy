#include <gsl/gsl>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <map>
//1,1,3,5,8,13,3,5,8,8,5
int main() {
	using Pair = std::map<int, int>;
	std::map<int, int> pair;

	std::vector<int> vec = { 1,1,3,5,8,13,3,5,8,8,5 };
	std::sort(vec.begin(), vec.end(), std::greater<int>());
	std::for_each(vec.begin(), vec.end(), [&](int n) {
		pair[n]++;
	});


	auto max = std::max_element(pair.begin(), pair.end(), [&](
		const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
		return p1.second < p2.second;
	});

	std::for_each(pair.begin(), pair.end(), [&](std::pair<int, int> n) {
		if (max->second == n.second) {
			std::cout << n.first << " " << n.second << std::endl;

		}
	});

}