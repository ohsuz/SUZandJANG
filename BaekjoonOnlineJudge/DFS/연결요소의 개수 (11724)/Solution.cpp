#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

bool dfs(int x){
	if (visited[x])
		return false;

	visited[x] = true;

	for (int i = 0;i < graph[x].size();i++) {
		int y = graph[x][i];
		if (!visited[y]) dfs(y);
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
		if (dfs(i))
			result++;
	}

	cout << result;
}