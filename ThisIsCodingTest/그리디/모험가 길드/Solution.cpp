#include <iostream>
#include <vector>

using namespace std;

int N, result;
vector<int> arr;

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	int num = 0;
	for (int i = 0;i < arr.size();i++) {
		num++;
		if (num >= arr[i]) {
			result++;
			num = 0;
		}
	}

	cout << result;
}