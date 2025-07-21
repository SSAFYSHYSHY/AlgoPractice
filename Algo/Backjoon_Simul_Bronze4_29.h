#pragma once
#include <iostream>
#include <string>

using namespace std;

int dx[15] = { 'A','a','b','D','d','g','e','O','o','P','p','Q','q','R','@' };

int main() {
	string s;

	getline(cin, s);

	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < 15; j++) {
			if (s[i] == dx[j]) {
				ans++;
			}
		}

		if (s[i] == 'B') {
			ans += 2;
		}
	}

	cout << ans;
}