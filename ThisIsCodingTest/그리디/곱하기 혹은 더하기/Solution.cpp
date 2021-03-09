#include <iostream>
#include <string>

using namespace std;

string s;
int result;

int main() {
	cin >> s;

	for (int i = 0;i < s.length();i++) {
		if (result <= 1 || s[i] <= 1)
			result += (s[i] - '0');
		else
			result *= (s[i] - '0');
	}

	cout << result;
}