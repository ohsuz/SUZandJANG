#include <iostream>
#include <vector>

using namespace std;

int N, M, result;
int card[100][100];

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> card[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		int min = card[i][0];
		for (int j = 1;j < M;j++) {
			if (min > card[i][j])
				min = card[i][j];
		}
		if (result < min)
			result = min;
	}

	cout << result;

}