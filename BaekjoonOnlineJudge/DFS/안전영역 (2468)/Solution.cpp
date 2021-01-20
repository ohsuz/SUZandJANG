#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> graph;
vector<vector<int>> temp;

bool dfs(int x, int y,int height) {
	if (x <= -1 || x >= N || y <= -1 || y >= N || temp[x][y] <=height)
		return false;
	
	if (temp[x][y] > height) {
		temp[x][y] = height;

		dfs(x - 1, y, height);
		dfs(x, y - 1, height);
		dfs(x + 1, y, height);
		dfs(x, y + 1, height);

		return true;
	}
}

int main() {
	int result = 0;

	cin >> N;

	graph.assign(N, vector<int>(N, 0));
	temp.assign(N, vector<int>(N, 0));

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int height;
			cin >> height;
			graph[i][j] = height;
		}
	}

	for (int k = 0;k <= 100;k++) {
		int count = 0;
		copy(graph.begin(),graph.end(),temp.begin());
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (dfs(i, j, k))
					count++;
			}
		}
		if (count>result)
			result = count;
	}

	cout << result;
}