#include <iostream>
#include <vector>

using namespace std;

vector<int> result;
int d[11];

int main() {
	int T;
	cin >> T;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	while (T--) {
		int n;
		cin >> n;

		if (n == 1 || n == 2 || n == 3)
			result.push_back(d[n]);
		else {
			for (int i = 4;i <= n;i++) {
				d[i] = d[i - 1] + d[i - 2] + d[i - 3];
			}
			result.push_back(d[n]);
		}
	}

	for (int i = 0;i < result.size();i++)
		cout << result[i] << endl;

}