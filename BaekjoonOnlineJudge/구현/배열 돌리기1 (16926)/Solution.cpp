#include <iostream>
#include <cstring>

//무슨 이딴 문제가.....................

using namespace std;

int graph[300][300];
bool visited[300][300];
int N, M, R;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(int x, int y, int temp, int count) {
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
			continue;
		}

		if (!visited[nx][ny] && (nx == count || ny == count || nx == N - (count+1) || ny == M - (count+1))) {
			int temp2 = graph[nx][ny];
			graph[nx][ny] = temp;
			visited[nx][ny] = true;
			dfs(nx, ny, temp2, count);
			break;
		}
	}
}

void rotation() {
	int min = N;

	if (N > M)
		min = M;
	
	int x = 0, y = 0;
	int i = 0;
	bool check = false;
	int tmp1 = graph[x][y], tmp2;
	while (true) {

		if (i >= min / 2)
			break;

		if (x == i && y == i && check) {
			check = false;
			i++;
			x = i;
			y = i;
			tmp1 = graph[x][y];
			continue;
		}

		check = true;

		if (x < N - (i + 1) && y == i) {
			tmp2 = graph[x + 1][y];
			graph[x + 1][y] = tmp1;
			tmp1 = tmp2;
			x = x + 1;
			y = y;
		}
		else if (x == N - (i + 1) && y < M - (i + 1)) {
			tmp2 = graph[x][y + 1];
			graph[x][y + 1] = tmp1;
			tmp1 = tmp2;
			x = x;
			y = y + 1;
		}
		else if (x > i && y == M - (i + 1)) {
			tmp2 = graph[x - 1][y];
			graph[x - 1][y] = tmp1;
			tmp1 = tmp2;
			x = x - 1;
			y = y;
		}
		else if (x == i && y > i) {
			tmp2 = graph[x][y - 1];
			graph[x][y - 1] = tmp1;
			tmp1 = tmp2;
			x = x;
			y = y - 1;
		}
	}
}

int main() {
	cin >> N >> M >> R;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			int n;
			cin >> n;
			graph[i][j] = n;
		}
	}

	int min = N;
	if (N > M)
		min = M;

	while (R--) {
		for (int i = 0;i < min/2;i++) {
			dfs(i, i,graph[i][i], i);
		}
		memset(visited, false, sizeof(visited));
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
}