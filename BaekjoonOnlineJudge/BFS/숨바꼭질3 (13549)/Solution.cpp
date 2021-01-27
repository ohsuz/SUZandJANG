#include <iostream>
#include <queue>

using namespace std;

int N, K;
int visited[100001];

struct compare {
	bool operator()(pair<pair<int, int>,int> a, pair<pair<int, int>,int> b) {
		if (a.second == b.second)
			return a.first.second > b.first.second;
		return a.second > b.second;
	}
};

int bfs(int x) {
	priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,compare> q;
	q.push({ {x,0},1 });
	visited[x] = -1;

	if (x == K)
		return 0;

	while (!q.empty()) {
		int x = q.top().first.first;
		int second = q.top().first.second;
		int count = q.top().second;
		q.pop();

		if (x == K) {
			return second;
		}

		if ((x - 1) >= 0 && (x - 1) <= 100000) {
			if ((visited[x - 1] > second + 1) || visited[x - 1] == 0) {
				visited[x - 1] = second + 1;
				q.push({ { x - 1,second + 1 },count + 1 });
			}
		}

		if ((x + 1) >= 0 && (x + 1) <= 100000) {
			if ((visited[x + 1] > second + 1) || visited[x + 1] == 0) {
				visited[x + 1] = second + 1;
				q.push({ { x + 1,second + 1 },count + 1 });
			}
		}

		if (2 * x >= 0 && 2 * x <= 100000) {
			if ((visited[2 * x] > second) || visited[2 * x] == 0) {
				visited[2 * x] = second;
				q.push({ { 2 * x , second },count + 1 });
			}
		}
	}
}

int main() {
	cin >> N >> K;
	cout << bfs(N);
}