#include <iostream>

using namespace std;

int N, K, result;

int main() {
	cin >> N >> K;

	/*
	while (N != 1) {
		if (N % K == 0)
			N /= K;
		else
			N -= 1;

		result++;
	}
	*/

	while (true) {
		int target = (N / K) * K;
		result += (N - target);
		N = target;

		if (N < K)
			break;

		result += 1;
		N /= K;
	}

	result += (N - 1);

	cout << result;
}