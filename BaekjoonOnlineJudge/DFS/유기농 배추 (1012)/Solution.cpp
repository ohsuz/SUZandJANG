#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

bool dfs(int a, int b,int M,int N) {
	if (a <= -1 || a >= N || b <= -1 || b >= M || graph[a][b] == 0)
		return false;
	
	if (graph[a][b]==1) {
		graph[a][b] = 0;

		dfs(a-1,b,M,N);
		dfs(a,b-1, M, N);
		dfs(a+1,b, M, N);
		dfs(a, b + 1, M, N);

		return true;
	}
}

int main() {
	int test, M, N, K;
	vector<int> result;

	cin >> test;

	for (int i = 0;i < test;i++) {
		cin >> M >> N >> K;
		graph.assign(N, vector<int>(M, 0));

		for (int i = 0;i < K;i++) {
			int a, b;
			cin >> a >> b;
			graph[b][a] = 1;
		}

		int count = 0;

		for (int i = 0;i < N;i++)
			for (int j = 0;j < M;j++)
				if (dfs(i, j, M, N))
					count++;

		result.push_back(count);
	}

	for (int i = 0;i < result.size();i++)
		cout << result[i] << endl;

}