#include <iostream>
#include <vector>

using namespace std;

int student[100001];
vector<bool> visited;
vector<bool> complete;

int dfs(int x) {
	int count = 0;
	int y = student[x];
	visited[x] = true;

	if (!visited[y])
		count = dfs(y);
	else {
		if (!complete[y]) {
			count = 1;
			for (int i = y;i != x;i = student[i])
				count++;
		}
	}
	complete[x] = true;
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T,n;
	vector<int> result;

	cin >> T;

	while (T--) {
		cin >> n;
		visited.assign(n + 1, false);
		complete.assign(n + 1, false);

		for (int i = 1;i <= n;i++) {
			int x;
			cin >> x;
			student[i] = x;
		}

		int count = 0;
		for (int i = 1;i <= n;i++) {
			if (!complete[i])
				count+=dfs(i);
		}

		result.push_back(n-count);
	}

	for (int i = 0;i < result.size();i++) {
		cout << result[i] << '\n';
	}
}