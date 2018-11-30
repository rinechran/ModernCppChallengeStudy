#include <gsl/gsl>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>


template <typename T, int N>
class CircularBuffer {
public:
	CircularBuffer() :mCount(0), start(0), end(0) {

	}

	void push(int n) {

		if (end + 1 % N == start % N) throw std::runtime_error("all");

		mArr[end %N] = n;
		end++;
		mCount++;

	}
	T pop() {
		if (empty()) throw std::runtime_error("empty");
		mCount--;
		return mArr[start++ % N];
	}
	bool empty() {
		return !size();
	}
	bool full() {
		return 0;
	}
	int size() {
		return mCount;
	}
	int capacity() {

	}
	int mCount;
	std::uint32_t start;
	std::uint32_t end;

	T mArr[N];


};
int main() {
	CircularBuffer<int, 10> a;
	a.push(10);
	std::cout << a.pop();
}