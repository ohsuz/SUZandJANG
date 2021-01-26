#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int order[100001];
bool visited[100001];

int bfs(int x) {
	int second = 0;
	queue<pair<int, int>> q;
	q.push({ x,0 });

	if (x == K)
		return second;
	
	while (!q.empty()) {
		int x = q.front().first;
		second = q.front().second;
		q.pop();

		if (x == K) {
			return second;
		}

		if (!visited[x - 1]&&0<=(x-1)&&(x-1)<=100000) {
			visited[x - 1] = true;
			order[x - 1] = x;
			q.push({ x - 1,second + 1 });
		}

		if (!visited[x + 1] && 0 <= (x + 1) && (x + 1) <= 100000) {
			visited[x + 1] = true;
			order[x + 1] = x;
			q.push({ x + 1,second + 1 });
		}

		if (!visited[2 * x] && 0 <= (2 * x) && (2 * x) <= 100000) {
			visited[2 * x] = true;
			order[2 * x] = x;
			q.push({ 2 * x,second + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	vector<int> result;

	if (N != K) {
		cout << bfs(N) << '\n';

		for (int i = K;i != N;i = order[i]) {
			result.push_back(i);
		}

		result.push_back(N);

		for (int i = result.size() - 1;i >= 0;i--) {
			cout << result[i] << ' ';
		}
	}

	if (N == K) {
		cout << 0 << '\n';
		cout << N;
	}
}