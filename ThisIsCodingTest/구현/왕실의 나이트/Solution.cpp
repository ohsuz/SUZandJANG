#include <iostream>
#include <string>

using namespace std;

string position;
int dx[] = { -1,-1,1,1,-2,-2,2,2 };
int dy[] = { 2,-2,2,-2,1,-1,1,-1 };

int main() {
	int count = 0;

	cin >> position;

	int x = position[1] - '0';
	int y = position[0] - 96;

	for (int i = 0;i < 8;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > 8 || ny > 8)
			continue;

		count++;
	}

	cout << count;
}