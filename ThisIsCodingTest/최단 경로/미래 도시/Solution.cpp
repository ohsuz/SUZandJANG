#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

int N, M, X, K;
int graph[101][101];

int main() {
	cin >> N >> M;

	for (int i = 0;i < 101;i++)
		fill(graph[i], graph[i] + 101, INF);

	for (int a = 1;a <= N;a++)
		graph[a][a] = 0;

	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	cin >> X >> K;

	for (int k = 1;k <= N;k++) {
		for (int a = 1;a <= N;a++) {
			for (int b = 1;b <= N;b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	if (graph[1][X] != INF && graph[K][X] != INF)
		cout << graph[1][K] + graph[K][X];
	else
		cout << -1;
}