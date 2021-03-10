#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M;
int graph[20][20];
int d[20][20];

int main() {
	cin >> T;
	while (T--) {
		int result = 0;

		cin >> N >> M;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				cin >> graph[i][j];
			}
		}

		for (int i = 0;i < N;i++) {
			d[i][0] = graph[i][0];
		}

		for (int i = 1;i < M;i++) {
			for (int j = 0;j < N;j++) {
				int leftup, leftdown, left;

				if (i == 0)
					leftup = 0;
				else leftup = d[j - 1][i - 1];

				if (i == N - 1)
					leftdown = 0;
				else leftdown = d[j + 1][i - 1];

				left = d[j][i - 1];
				
				d[j][i] = max({ left, leftup, leftdown }) + graph[j][i];
			}
		}

		for (int i = 0;i < N;i++) {
			result = max(result, d[i][M - 1]);
		}

		cout << result << endl;
	}
}