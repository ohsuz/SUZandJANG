#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
	int result = 0;
	bool check = true;

	cin >> s;

	for (int i = 0;i < s.length() - 1;i++) {
		if (s[i] != s[i + 1]) {
			if (check) {
				result++;
				check = false;
			}
			else {
				check = true;
			}
		}
	}

	cout << result;
}