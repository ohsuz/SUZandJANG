#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N;
vector<string> graph;
bool visited[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool bfs_first(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	if (visited[x][y])
		return false;

	visited[x][y] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx<0 || nx>=N || ny<0 || ny>=N)
				continue;

			if (!visited[nx][ny] && graph[nx][ny] == graph[x][y]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

	return true;
}

bool bfs_second(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	if (!visited[x][y])
		return false;

	visited[x][y] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx<0 || nx>=N || ny<0 || ny>=N)
				continue;

			if (visited[nx][ny]) {
				if (graph[nx][ny] == graph[x][y]||(graph[nx][ny]!='B'&&graph[x][y]!='B')) {
					visited[nx][ny] = false;
					q.push({ nx,ny });
				}
			}
		}
	}

	return true;
}

int main() {
	cin >> N;
	int count1 = 0, count2 = 0;
	
	for (int i = 0;i < N;i++) {
		string s;
		cin >> s;
		graph.push_back(s);
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (bfs_first(i, j))
				count1++;
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (bfs_second(i, j))
				count2++;
		}
	}

	cout << count1 << ' ' << count2;
}