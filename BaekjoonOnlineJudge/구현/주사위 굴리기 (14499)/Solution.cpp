//전역변수, 지역변수 시간 차이?
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, curX, curY, command;
int map[20][20];
int dice[7];

void change(int d) {
	int temp[7];
	copy(dice, dice + 7, temp);

	if (d == 1) {
		dice[1] = temp[4];
		dice[3] = temp[1];
		dice[4] = temp[6];
		dice[6] = temp[3];
	}
	else if (d == 2) {
		dice[1] = temp[3];
		dice[3] = temp[6];
		dice[4] = temp[1];
		dice[6] = temp[4];
	}
	else if (d == 3) {
		dice[1] = temp[5];
		dice[2] = temp[1];
		dice[5] = temp[6];
		dice[6] = temp[2];
	}
	else if (d == 4) {
		dice[1] = temp[2];
		dice[2] = temp[6];
		dice[5] = temp[1];
		dice[6] = temp[5];
	}

	if (map[curX][curY] == 0)
		map[curX][curY] = dice[6];
	else {
		dice[6] = map[curX][curY];
		map[curX][curY] = 0;
	}


}

bool move(int d) {

	int x = curX;
	int y = curY;

	if (d == 1) {
		x = x;
		y = y + 1;
	}
	else if (d == 2) {
		x = x;
		y = y - 1;
	}
	else if (d == 3) {
		x = x - 1;
		y = y;
	}
	else if (d == 4) {
		x = x + 1;
		y = y;
	}

	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;

	curX = x;
	curY = y;

	change(d);

	return true;
}

int main() {

	cin >> N >> M >> curX >> curY >> command;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			int a;
			cin >> a;
			map[i][j] = a;
		}
	}

	for (int i = 0;i < command;i++) {
		int a;
		cin >> a;
		if (move(a))
			cout << dice[1] << endl;
	}

}