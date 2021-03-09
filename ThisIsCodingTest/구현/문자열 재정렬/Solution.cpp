#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, result;
int sum;

int main() {
	cin >> s;

	for (int i = 0;i < s.length();i++) {
		if (65 <= s[i] && s[i] <= 90)
			result += s[i];
		else
			sum += (s[i] - '0');
	}

	sort(result.begin(),result.end());

	cout << result << sum;
}