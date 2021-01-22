#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int graph[25][25];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int bfs(int x, int y) {
	graph[x][y] = 0;
	int count=1;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny<0 || ny>=N)
				continue;

			if (graph[nx][ny] == 1) {
				graph[nx][ny] = 0;
				count++;
				q.push({ nx,ny });
			}
		}
	}
	return count;
}

int main() {
	vector<int> result;

	cin >> N;

	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			scanf("%1d", &graph[i][j]);

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (graph[i][j] == 1)
				result.push_back(bfs(i, j));
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << endl;
	for (int i = 0;i < result.size();i++)
		cout << result[i] << endl;
}