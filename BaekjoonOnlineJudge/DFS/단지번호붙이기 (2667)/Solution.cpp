#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
int graph[25][25];

int dfs(int a,int b) {
	int count = 0;
	if(a<=-1||a>=n||b<=-1||b>=n||graph[a][b]==0)
		return 0;

	if (graph[a][b] == 1) {
		count++;
		graph[a][b] = 0;

		count += dfs(a - 1, b);
		count += dfs(a, b - 1);
		count += dfs(a + 1, b);
		count += dfs(a, b + 1);
		return count;
	}

	return 0;
}

int main() {
	cin >> n;
	vector<int> result;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++)
			scanf("%1d", &graph[i][j]);
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int count = dfs(i, j);
			if (count != 0) {
				result.push_back(count);
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << endl;

	for (int i = 0;i < result.size();i++)
		cout << result[i] << endl;
}
