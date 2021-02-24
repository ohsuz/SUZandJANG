#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
int d[1001];

int main() {
	cin >> N;
	for (int i = 1;i <= N;i++) {
		int money;
		cin >> money;
		arr[i] = money;
	}

	for (int i = 1;i <= N;i++) {
		d[i] = arr[i];
		for (int j = 1;j < i;j++) {
			d[i] = max(d[i], d[j] + d[i-j]);
		}
	}

	cout << d[N];
}