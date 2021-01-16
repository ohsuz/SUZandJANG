#include <iostream>
#include <vector>

using namespace std;

bool visited[101];
vector<int> computer[101];

void dfs(int x) {
	visited[x] = true;
	
	for (int i = 0;i < computer[x].size();i++) {
		int y = computer[x][i];
		if (!visited[y]) dfs(y);
	}

}

int main() {
	int cnum, pnum, count = 0;
	cin >> cnum >> pnum;

	for (int i = 0;i < pnum;i++) {
		int a, b;
		cin >> a >> b;
		computer[a].push_back(b);
		computer[b].push_back(a);
	}

	dfs(1);

	for (int i = 2;i <= cnum;i++) {
		if (visited[i]) count++;
	}

	cout << count;
}