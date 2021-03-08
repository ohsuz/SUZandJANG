#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, X;
vector<int> graph[300001];
vector<int> result;
bool visited[300001];

void bfs(int x) {
	queue<pair<int, int>> q;
	q.push({ x,0 });
	visited[x] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int d = q.front().second;
		q.pop();

		if (d == K) {
			result.push_back(x);
			continue;
		}

		for (int i = 0;i < graph[x].size();i++) {
			int nx = graph[x][i];
			if (!visited[nx]) {
				visited[nx] = true;
				q.push({ nx,d + 1 });
			}
		}
	}
}

int main() {
	cin >> N >> M >> K >> X;

	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	bfs(X);
	sort(result.begin(), result.end());

	if (result.empty())
		cout << -1;
	else {
		for (int i = 0;i < result.size();i++) {
			cout << result[i] << endl;
		}
	}
}