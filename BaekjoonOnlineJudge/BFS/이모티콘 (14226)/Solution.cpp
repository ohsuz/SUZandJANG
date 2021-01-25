#include <iostream>
#include <queue>

using namespace std;

int S;
bool visited[2001][2001];

int bfs(int x) {
	queue<pair<pair<int,int>,int>> q;
	q.push({{ x,1 },1 });

	while (!q.empty()) {
		int x = q.front().first.first;
		int second = q.front().first.second;
		int board = q.front().second;
		q.pop();

		if (x == S)
			return second;

		if ((x > 0 && x < 2001) && (board >0 && board + x < 2001)) {
			if (!visited[x][x]) {
				visited[x][x] = true;
				q.push({ {x,second + 1},x });
			}
			if (!visited[x + board][board]) {
				visited[x+board][board] = true;
				q.push({ {x + board,second + 1},board });
			}
			if (!visited[x - 1][board]) {
				visited[x-1][board] = true;
				q.push({ {x - 1,second + 1},board });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S;
	cout << bfs(1);
}