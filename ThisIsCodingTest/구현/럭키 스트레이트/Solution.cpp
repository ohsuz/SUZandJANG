#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;

int main() {
	cin >> N;

	int count = 0;
	while (N > 0) {
		arr.push_back(N % 10);
		N /= 10;
		count++;
	}

	int sum1 = 0, sum2 = 0;
	for (int i = 0;i < count / 2;i++) {
		sum1 += arr[i];
	}

	for (int i = count / 2;i < arr.size();i++) {
		sum2 += arr[i];
	}

	if (sum1 == sum2) {
		cout << "LUCKY";
	}
	else {
		cout << "READY";
	}
}