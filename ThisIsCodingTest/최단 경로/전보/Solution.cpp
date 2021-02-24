#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int N, M, start;
vector<pair<int, int>> graph[30001];
int d[30001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist)
			continue;

		for (int i = 0;i < graph[now].size();i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main() {
	int count = 0, time = 0;

	cin >> N >> M >> start;

	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	fill(d, d + 30001, INF);

	dijkstra(start);
	
	for (int i = 1;i <= N;i++) {
		if (d[i] == INF || i == start)
			continue;
		else {
			count++;
			time = max(time,d[i]);
		}
			
	}

	cout << count << ' ' << time;
}