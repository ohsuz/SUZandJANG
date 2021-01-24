#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[2000];
bool visited[2000];

bool dfs(int x,int index) {

	visited[x] = true;

	if (index == 5)
		return true;

	for (int i = 0;i < graph[x].size();i++) {
		int y = graph[x][i];
		if (!visited[y])
			if (dfs(y, index + 1))
				return true;
	}

	visited[x] = false;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0;i < N;i++) {
		if (dfs(i, 1)) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;
}