#include <iostream>
#include <vector>

using namespace std;

long long d[30001];

int main() {
	int X;
	cin >> X;

	for (int i = 2;i <= X;i++) {
		int x;

		if (i % 5 == 0) {
			x = i / 5;
			if(d[x] + 1 < d[i] || d[i] == 0)
				d[i] = d[x] + 1;
		}
		if (i % 3 == 0) {
			x = i / 3;
			if (d[x] + 1 < d[i] || d[i] == 0)
				d[i] = d[x] + 1;
		}
		if (i % 2 == 0) {
			x = i / 2;
			if (d[x] + 1 < d[i] || d[i] == 0)
				d[i] = d[x] + 1;
		}

		x = i - 1;
		if (d[x] + 1 < d[i] || d[i] == 0)
			d[i] = d[x] + 1;

	}

	cout << d[X];
}