#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

bool bfs(int x) {
	queue<int> q;
	q.push(x);

	if (visited[x])
		return false;

	visited[x] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0;i < graph[x].size();i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				visited[y] = true;
				q.push(y);
			}
		}
	}

	return true;
}

int main() {
	int n, m, result = 0;
	cin >> n >> m;

	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1;i <= n;i++) {
		if (bfs(i))
			result++;
	}

	cout << result;
}