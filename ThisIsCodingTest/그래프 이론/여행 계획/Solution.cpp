#include <iostream>
#include <vector>

using namespace std;

int N, M;
int parent[501];

int findParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		parent[i] = i;
	}
	
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			int x;
			cin >> x;
			if (x == 1 && i<=j)
				unionParent(i, j);
		}
	}

	vector<int> arr;
	for (int i = 0;i < M;i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	for (int i = 0;i < M;i++) {
		if (findParent(arr[i]) != findParent(arr[i + 1])) {
			cout << "NO";
			exit(1);
		}
	}

	cout << "YES";
}