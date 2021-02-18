#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0;i < N;i++) {
		cout << arr[i] << ' ';
	}
}