#include <iostream>
#include <vector>

using namespace std;

int d[101];
int N;
vector<int> store = { 0 };

int main() {
	cin >> N;
	for (int i = 1;i <= N;i++) {
		int x;
		cin >> x;
		store.push_back(x);
	}

	for (int i = 1;i <= N;i++) {
		if (i == 1)
			d[i] = store[i];
		else if (i == 2) {
			d[i] = store[i];
			if (d[i] < d[i - 1])
				d[i] = d[i - 1];
		}
		else if (i != 1 && i != 2) {
			d[i] = store[i] + d[i - 2];
			if (d[i] < d[i - 1])
				d[i] = d[i - 1];
		}
	}

	cout << d[N];
}