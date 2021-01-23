#include <iostream>
#include <queue>

using namespace std;

int M, N;
int graph[1000][1000];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int bfs(queue<pair<int, int>> ripe) {
	int day = 0;

	while (!ripe.empty()) {
		int x = ripe.front().first;
		int y = ripe.front().second;
		ripe.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (graph[nx][ny] == 0) {
				graph[nx][ny] = graph[x][y]+1;
				ripe.push({ nx,ny });
				if (graph[nx][ny] - 1 > day) {
					day = graph[nx][ny] - 1;
				}
			}
		}
	}

	return day;
}

int main() {
	int day;
	queue<pair<int, int>> ripe;
	cin >> M >> N;
	for(int i=0;i<N;i++)
		for (int j = 0;j < M;j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				ripe.push({ i,j });
			}
		}

	day = bfs(ripe);

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (graph[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << day;
}