#include <iostream>

using namespace std;

int main() {
	int N;
	int result = 0;
	
	cin >> N;

	while (true) {
		if (N % 5 == 0) {
			result += N / 5;
			break;
		}
		else {
			N -= 3;
			result++;
		}

		if (N < 0) {
			result = -1;
			break;
		}
	}

	cout << result;
}