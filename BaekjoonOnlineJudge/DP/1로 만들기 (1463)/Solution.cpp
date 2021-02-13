#include <iostream>

using namespace std;

int N;
int d[1000000];

int main() {
	cin >> N;
	for (int i = 2;i <= N;i++) {
		d[i] = d[i - 1] + 1;
		if (i % 3 == 0) {
			if (d[i] > d[i / 3] + 1)
				d[i] = d[i / 3] + 1;
		}
		if (i % 2 == 0) {
			if (d[i] > d[i / 2] + 1)
				d[i] = d[i / 2] + 1;
		}
	}
	cout << d[N];
}