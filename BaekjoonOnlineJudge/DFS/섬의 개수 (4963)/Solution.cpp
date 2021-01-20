#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

bool dfs(int x, int y, int w, int h) {
	if (x <= -1 || x >= h || y <= -1 || y >= w || graph[x][y] == 0)
		return false;

	if (graph[x][y] == 1) {
		graph[x][y] = 0;

		dfs(x - 1, y, w, h);
		dfs(x, y - 1, w, h);
		dfs(x + 1, y, w, h);
		dfs(x, y + 1, w, h);
		dfs(x - 1, y - 1, w, h);
		dfs(x - 1, y + 1, w, h);
		dfs(x + 1, y - 1, w, h);
		dfs(x + 1, y + 1, w, h);

		return true;
	}
}

int main() {
	int w, h;
	vector<int> result;

	while (true) {
		int count = 0;

		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		graph.assign(h, vector<int>(w, 0));

		for (int i = 0;i < h;i++)
			for (int j = 0;j < w;j++)
				cin >> graph[i][j];

		for (int i = 0;i < h;i++)
			for (int j = 0;j < w;j++)
				if (dfs(i,j,w,h))
					count++;
		result.push_back(count);

	}

	for (int i = 0;i < result.size();i++)
		cout << result[i] << endl;
}