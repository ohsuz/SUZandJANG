#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int parent[100001];
vector <pair<int, pair<int, int>>> edges;
int result;

int findParent(int x) {
	if (x == parent[x])
		return x;
	else
		parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	cin >> N >> M;

	for (int i = 1;i <= N;i++) {
		parent[i] = i;
	}

	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c,{a,b} });
	}

	sort(edges.begin(), edges.end());

	int max = 0;
	for (int i = 0;i < edges.size();i++) {
		int c = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			result += c;
			//비교 안해도 마지막에 나오는 애가 가장 큼. 여기서 mac = c 해도 된다.
			if (max <= c)
				max = c;
		}
	}

	result -= max;
	cout << result;
}