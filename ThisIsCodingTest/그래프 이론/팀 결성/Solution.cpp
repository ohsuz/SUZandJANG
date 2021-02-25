#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
int parent[100001];
vector<string> result;

int findParent(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = findParent(parent[x]);
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

	for (int i = 0;i <= N;i++) {
		parent[i] = i;
	}

	for (int i = 0;i < M;i++) {
		int n, a, b;
		cin >> n >> a >> b;
		if (n == 0)
			unionParent(a, b);
		else if (n == 1) {
			if (parent[a] == parent[b])
				result.push_back("YES");
			else
				result.push_back("NO");
		}
	}

	for (int i = 0;i < result.size();i++) {
		cout << result[i] << endl;
	}
}