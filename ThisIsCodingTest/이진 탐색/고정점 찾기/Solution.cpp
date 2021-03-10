#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;

int binarySearch(int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == mid)
			return mid;
		else if (arr[mid] > mid) end = mid - 1;
		else start = mid + 1;
	}

	return -1;
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	cout << binarySearch(0, N - 1);

}