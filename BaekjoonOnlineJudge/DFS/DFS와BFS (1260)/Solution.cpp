#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visitedDFS[1001];
bool visitedBFS[1001];
vector<int> graph[1001];

void dfs(int x) {
	visitedDFS[x] = true;
	cout << x << ' ';
	for (int i = 0;i < graph[x].size();i++) {
		int y = graph[x][i];
		if (!visitedDFS[y]) dfs(y);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);

	visitedBFS[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		
		for (int i = 0;i < graph[x].size();i++) {
			int y = graph[x][i];
			if (!visitedBFS[y]) {
				q.push(y);
				visitedBFS[y] = true;
			}
		}
	}
}

int main() {
	int N,M,V;

	cin >> N >> M >> V;

	for (int i = 1;i <= M;i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1;i <=N;i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V);
	cout << endl;
	bfs(V);
}