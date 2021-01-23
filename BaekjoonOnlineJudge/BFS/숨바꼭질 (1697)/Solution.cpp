#include <iostream>
#include <queue>

using namespace std;

int N, K;
int graph[100001];
bool visited[100001];

int bfs(int x) {
	int second = 0;
	queue<pair<int,int>> q;
	q.push({ x,0 });
	
	if (x == K)
		return second;

	while (!q.empty()) {
		int x = q.front().first;
		second = q.front().second + 1;
		q.pop();
		for (int i = 0;i < 3;i++) {
			int nx;
			if (i == 0)
				nx = x - 1;
			else if (i == 1)
				nx = x + 1;
			else if (i == 2)
				nx = x * 2;

			if (nx < 0 || nx>100000)
				continue;

			if (!visited[nx]) {
				visited[nx] = true;
				q.push({ nx,second });
			}

			if (nx == K) {
				return second;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	cout << bfs(N);
}