#include <gsl/gsl>
#include <vector>

template <class T>

class PriorityQueue {

public:

	PriorityQueue() : mArr{ 0 } {


	}



	std::uint32_t size() {
		return mArr.size() - 1;
	}




	void push(int n) {

		mArr.push_back(n);
		int index = mArr.size() - 1;

		while (index != START_INDEX) {
			int parentIndex = index / 2;
			if (mArr[parentIndex] < mArr[index]) {
				std::swap(mArr[parentIndex], mArr[index]);
			}
			index /= 2;
		}

	}

	T pop() {

		if (empty()) throw std::exception("empty");
		int index = 1;
		int subIndex = 0;
		mArr[index] = *(mArr.rbegin());

		index = index * 2;
		while (index < mArr.size()) {
			int sub = 0;
			if (index + 1 < mArr.size()
				&& mArr[index] < mArr[index + 1]) sub = 1;
			if (mArr[index / 2] < mArr[index + sub])
				std::swap(mArr[index / 2], mArr[index + sub]);
			index = index * 2;
		
		mArr.pop_back();

	}

	bool empty() {
		return mArr.size() == 1;
	}

	std::vector<T> mArr;
	static int const  START_INDEX;

};

template <class T>

int const PriorityQueue<T>::START_INDEX = 1;



int main()

{

	PriorityQueue<int> priorityQueue;
	priorityQueue.push(3);
	priorityQueue.push(2);
	priorityQueue.pop();

}