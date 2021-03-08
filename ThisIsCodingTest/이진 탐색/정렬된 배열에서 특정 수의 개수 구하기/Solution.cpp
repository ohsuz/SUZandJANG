#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, x, pos1, pos2;
vector<int> arr;

void binarySearch(vector<int>& arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] == target) {
			if (pos1 == 0 && pos2 == 0) {
				pos1 = mid;
				pos2 = mid;
			}
			else {
				pos1 = min(mid, pos1);
				pos2 = max(mid, pos2);
			}
			binarySearch(arr, target, 0, mid - 1);
			binarySearch(arr, target, mid + 1, end);
			break;
		}
		else if (arr[mid] > target) end = mid - 1;
		else start = mid + 1;
	}
}

int main() {
	cin >> N >> x;
	
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	binarySearch(arr, x, 0, N - 1);

	if (pos2 - pos1 == 0)
		cout << -1;
	else
		cout << pos2 - pos1 + 1;
}