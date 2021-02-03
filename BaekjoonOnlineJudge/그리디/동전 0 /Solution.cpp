#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	vector<int> money;
	int sum = 0, result = 0;

	cin >> N >> K;
	
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		if (K < a)
			continue;
		money.push_back(a);
	}

	for (int i = money.size() - 1;i >= 0;i--) {
		if (K - sum >= money[i]) {
			result += (K - sum) / money[i];
			sum += (K - sum) / money[i] * money[i];
		}

		if (sum == K)
			break;
	}

	cout << result;
}