#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> A;
vector<int> B;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int result = 0;
	cin >> N >> K;

	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}

	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		B.push_back(num);
	}

	sort(A.begin(), A.end(), compare);
	sort(B.begin(), B.end(), compare);

	for (int i = 0;i < N - K;i++)
		result += A[i];

	for (int i = N - K, j = 0;i < N;i++, j++) {
		swap(A[i], B[j]);
		result += A[i];
	}

	cout << result;
}