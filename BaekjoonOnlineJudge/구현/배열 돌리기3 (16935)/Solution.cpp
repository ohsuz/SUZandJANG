#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int graph[100][100];
int N, M;

void one() {
	int temp[100][100];
	memcpy(temp, graph, sizeof(graph));

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			graph[i][j] = temp[N - (i + 1)][j];
		}
	}
}

void two() {
	int temp[100][100];
	memcpy(temp, graph, sizeof(graph));

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			graph[i][j] = temp[i][M - (j + 1)];
		}
	}
}

void three() {
	int temp[100][100];
	memcpy(temp, graph, sizeof(graph));

	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			graph[i][j] = temp[N - (j + 1)][i];
		}
	}

	int tmp = N;
	N = M;
	M = tmp;
}

void four() {
	int temp[100][100];
	memcpy(temp, graph, sizeof(graph));

	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			graph[i][j] = temp[j][M - (i+1)];
		}
	}

	int tmp = N;
	N = M;
	M = tmp;
}

void five() {
	int temp[100][100];
	memcpy(temp, graph, sizeof(graph));

	for (int i = 0;i < N / 2;i++) {
		for (int j = 0;j < M / 2;j++) {
			graph[i][j] = temp[N / 2 + i][j];
		}
		for (int j = M / 2;j < M;j++) {
			graph[i][j] = temp[i][j - M / 2];
		}
	}

	for (int i = N / 2;i < N;i++) {
		for (int j = 0;j < M / 2;j++) {
			graph[i][j] = temp[i][M / 2 + j];
		}
		for (int j = M / 2;j < M;j++) {
			graph[i][j] = temp[i - N / 2][j];
		}
	}
}

void six() {
	int temp[100][100];
	memcpy(temp, graph, sizeof(graph));

	for (int i = 0;i < N / 2;i++) {
		for (int j = 0;j < M / 2;j++) {
			graph[i][j] = temp[i][M / 2 + j];
		}
		for (int j = M / 2;j < M;j++) {
			graph[i][j] = temp[N / 2 + i][j];
		}
	}

	for (int i = N / 2;i < N;i++) {
		for (int j = 0;j < M / 2;j++) {
			graph[i][j] = temp[i - N / 2][j];
		}
		for (int j = M / 2;j < M;j++) {
			graph[i][j] = temp[i][j - M / 2];
		}
	}
}

int main() {
	int count;
	cin >> N >> M >> count;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			int a;
			cin >> a;
			graph[i][j] = a;
		}
	}
	for (int i = 0;i < count;i++) {
		int a;
		cin >> a;
		switch (a) {
		case 1:
			one();
			break;
		case 2:
			two();
			break;
		case 3:
			three();
			break;
		case 4:
			four();
			break;
		case 5:
			five();
			break;
		case 6:
			six();
			break;
		default:
			break;
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
}