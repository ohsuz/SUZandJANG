#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

int N, M;
int graph[101][101];

int main() {
	cin >> N >> M;
	
	for (int i = 0;i < 101;i++) {
		fill(graph[i], graph[i] + 101, INF);
	}

	for (int i = 1;i <= N;i++) {
		graph[i][i] = 0;
	}

	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}

	for (int k = 1;k <= N;k++) {
		for (int a = 1;a <= N;a++) {
			for (int b = 1;b <= N;b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	for (int a = 1;a <= N;a++) {
		for (int b = 1;b <= N;b++) {
			if (graph[a][b] == INF) {
				cout << 0 << ' ';
			}
			else
				cout << graph[a][b] << ' ';
		}
		cout << endl;
	}
}