#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());

	if (N % 2 == 0)
		cout << arr[N / 2 - 1];
	else
		cout << arr[N / 2];
}