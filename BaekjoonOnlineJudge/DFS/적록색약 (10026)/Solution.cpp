/*
적록색약 문제 : 시간복잡도 줄여보기 (dfs,bfs) 
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<string> graph;
bool visited[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs_first(int a, int b) {
	int x = a;
	int y = b;

	visited[x][y] = true;

	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		
		if (!visited[nx][ny] && graph[x][y] == graph[nx][ny]) {
			visited[nx][ny] = true;
			dfs_first(nx, ny);
		}
	}
}

void dfs_second(int a, int b) {
	int x = a;
	int y = b;

	visited[x][y] = false;

	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;

		if (visited[nx][ny] && (graph[x][y] == graph[nx][ny] || (graph[x][y] != 'B'&&graph[nx][ny] != 'B'))) {
			visited[nx][ny] = false;
			dfs_second(nx, ny);
		}
	}
}

int main() {
	int count1 = 0, count2 = 0;

	cin >> N;

	for (int i = 0;i < N;i++) {
		string s;
		cin >> s;
		graph.push_back(s);
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (!visited[i][j]) {
				dfs_first(i, j);
				count1++;
			}
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (visited[i][j]) {
				dfs_second(i, j);
				count2++;
			}
		}
	}

	cout << count1 << ' ' << count2;
}