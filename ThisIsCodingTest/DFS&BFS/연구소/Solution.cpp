//처음부터 끝까지 답지 참고한 코드..ㅎㅎ 모든 경우의수 조합 => dfs 사용하는 것이 핵심..
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, result;
int graph[8][8];
int temp[8][8];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void virus(int x, int y) {
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (temp[nx][ny] == 0) {
				temp[nx][ny] = 2;
				virus(nx, ny);
			}
		}
	}
}

int getdomain() {
	int d = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (temp[i][j] == 0)
				d++;
		}
	}
	
	return d;
}

void dfs(int count) {
	if (count == 3) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				temp[i][j] = graph[i][j];
			}
		}

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (temp[i][j] == 2) {
					virus(i, j);
				}
			}
		}

		result = max(result, getdomain());
		return;
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (graph[i][j] == 0) {
				graph[i][j] = 1;
				count += 1;
				dfs(count);
				graph[i][j] = 0;
				count -= 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> graph[i][j];
		}
	}

	dfs(0);
	cout << result;
}