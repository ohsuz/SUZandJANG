#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class student {
public:
	string name;
	int score;

	student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	bool operator <(student &other) {
		return this->score < other.score;
	}
};

int N;
vector<student> arr;

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		string name;
		int score;
		cin >> name >> score;
		arr.push_back(student(name,score));
	};

	sort(arr.begin(), arr.end());
	for (int i = 0;i < N;i++) {
		cout << arr[i].name << ' ';
	}
}