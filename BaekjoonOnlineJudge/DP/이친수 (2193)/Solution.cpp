#include <iostream>

using namespace std;

int N;
long long d[91];

int main() {
	cin >> N;

	d[1] = 1;
	d[2] = 1;

	for (int i = 3;i <= N;i++) {
		d[i] = 1;
		for (int j = 1;j < i - 1;j++) {
			d[i] += d[j];
		}
	}

	cout << d[N];
}