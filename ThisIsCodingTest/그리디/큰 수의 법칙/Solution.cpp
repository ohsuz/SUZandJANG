#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<int> arr;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int result = 0;
	cin >> N >> M >> K;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end(), compare);
	
	int i = 1;
	while (M--) {
		if (i > K) {
			result += arr[1];
			i = 1;
			continue;
		}
		result += arr[0];
		i++;
	}

	/* M의 크기가 100억이상일 경우
	int first = arr[n - 1];
	int second = arr[n - 2];

	int cnt = (m / (k + 1)) * k;
	cnt += m % (k + 1);

	int result = 0;
	result += cnt * first;
	result += (m - cnt) * second;
	*/

	cout << result;
}