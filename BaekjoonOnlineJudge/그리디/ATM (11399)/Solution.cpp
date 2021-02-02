#include <iostream>
#include <vector>
#include <algorithm>

//sort 보다 quicksort 쓰면 더 빠름

using namespace std;

vector<int> people;
int N;

int main() {
	int total = 0;
	int sum = 0;

	cin >> N;
	for (int i = 0;i < N;i++) {
		int time;
		cin >> time;
		people.push_back(time);
	}

	sort(people.begin(), people.end());

	for (int i = 0;i < N;i++) {
		sum += people[i];
		total += sum;
	}

	cout << total;
}