#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int t;

int main() {
	cin >> t;

	while (t--) {
		int a = 0, b = 0;
		string s;
		cin >> s;

		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a') {
				a++;
			}
			else {
				b++;
			}

			ans = min({ a,b });
		}

		cout << ans << "\n";
	}
}