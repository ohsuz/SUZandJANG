#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> graph;

int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};

int bfs(int I, int startX, int startY, int X, int Y) {
	queue<pair<int, int>> q;
	q.push({ startX,startY });

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 8;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= I || ny < 0 || ny >= I) {
				continue;
			}
			
			if (graph[nx][ny] == 0 && (nx != startX || ny != startY)) {
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx,ny });
			}

			if (nx == X&&ny == Y) {
				return graph[nx][ny];
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> result;

	cin >> N;

	for (int i = 0;i < N;i++) {
		int I, startX, startY, X, Y;

		cin >> I;
		cin >> startX >> startY;
		cin >> X >> Y;

		graph.assign(I,vector<int>(I,0));
		result.push_back(bfs(I, startX, startY, X, Y));
	}

	for (int i = 0;i < result.size();i++)
		cout << result[i] << '\n';
}