#include <iostream>

using namespace std;

int N, M;
int x, y, d;
int map[50][50];
bool visited[50][50];

int moveX(int x) {
	int nx;

	switch (d)
	{
	case 0:
		nx = x - 1;
		break;
	case 1:
		nx = x;
		break;
	case 2:
		nx = x + 1;
		break;
	case 3:
		nx = x;
		break;
	}

	return nx;
}

int moveY(int y) {
	int ny;

	switch (d)
	{
	case 0:
		ny = y;
		break;
	case 1:
		ny = y + 1;
		break;
	case 2:
		ny = y;
		break;
	case 3:
		ny = y - 1;
		break;
	}

	return ny;
}

int main() {
	int count = 0 , result = 1;

	cin >> N >> M;
	cin >> x >> y >> d;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}

	visited[x][y] = true;

	while (true) {
		int nx, ny;

		if (count == 4) {
			count = 0;
			x = moveX(x);
			y = moveY(y);

			if (x < 0 || y < 0 || x >= N || y >= M) {
				break;
			}

			if (visited[x][y] || map[x][y] == 1)
				break;

			continue;
		}

		if (d == 0)
			d = 3;
		else
			d--;

		count++;

		nx = moveX(x);
		ny = moveY(y);

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
			continue;
		}

		if (!visited[nx][ny] && map[nx][ny] == 0) {
			visited[nx][ny] = true;
			x = nx;
			y = ny;
			result++;
			count = 0;
		}

	}

	cout << result;
}