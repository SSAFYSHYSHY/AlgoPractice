#pragma once
#include <iostream>
#include <string>

using namespace std;

int n, ans = 0;

int main() {
	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		if (s[0] == 'C') {
			ans++;
		}
	}

	cout << ans;
}