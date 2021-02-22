#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long d[101][11]; //일차원 배열 두개(d, temp) 선언해서 풀면 틀림 왜지..?
long long sum;

int main() {
	cin >> N;

	for (int i = 0;i <= 9;i++)
		d[1][i] = 1;

	for (int i = 2;i <= N;i++) {
		d[i][0] = d[i - 1][1] % 1000000000;
		for (int j = 1; j <= 9;j++) {
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000;
		}
	}

	for (int i = 1;i <= 9;i++)
		sum = (sum + d[N][i]) % 1000000000;

	cout << sum;
}