#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int indegree[501];
int times[501];
vector<int> graph[501];

void topologySort() {
	vector<int> result(501);
	queue<int> q;

	for (int i = 1;i <= N;i++) {
		result[i] = times[i];

		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0;i < graph[now].size();i++) {
			result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);
			indegree[graph[now][i]] -= 1;
			
			if (indegree[graph[now][i]] == 0) {
				q.push(graph[now][i]);
			}
		}
	}

	for (int i = 1;i <= N;i++) {
		cout << result[i] << endl;
	}
}

int main() {
	cin >> N;

	for (int i = 1;i <= N;i++) {
		int time;
		cin >> time;
		times[i] = time;

		int x;
		while (true) {
			cin >> x;
			if (x == -1)
				break;
			indegree[i] += 1;
			graph[x].push_back(i);
		}
	}

	topologySort();
}