#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool binary_search(vector<int> &store, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;

		if (store[mid] == target) return true;
		else if (store[mid] > target) end = mid - 1;
		else start = mid + 1;
	}

	return false;
}

int N, M;
vector<int> store;
bool store2[1000001];
set<int> store3;

int main() {

	/*binary_search
	cin >> N;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		store.push_back(a);
	}

	sort(store.begin(), store.end());

	cin >> M;
	for (int i = 0;i < M;i++) {
		int target;
		cin >> target;
		if (search(store, target, 0, N-1))
			cout << "yes" << ' ';
		else
			cout << "no" << ' ';
	}
	*/

	/*counting sort
	cin >> N;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		store2[a] = true;
	}

	cin >> M;
	for (int i = 0;i < M;i++) {
		int target;
		cin >> target;
		if (store2[target])
			cout << "yes" << ' ';
		else
			cout << "no" << ' ';
	}
	*/

	/*set
	cin >> N;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		store3.insert(a);
	}

	cin >> M;
	for (int i = 0;i < M;i++) {
		int target;
		cin >> target;
		if (store3.count(target))
			cout << "yes" << ' ';
		else
			cout << "no" << ' ';
	}
	*/
}