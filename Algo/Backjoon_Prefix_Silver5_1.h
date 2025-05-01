#pragma once
#include <iostream>
#include <string>

using namespace std;

int n, ans;
string s;

int main() {
	cin >> s;
	n = s.length();

	for (int i = 1; i < n; i++) {
		int l = i - 1;
		int r = i;
		int suml = 0, sumr = 0;

		while (l > -1 && r < n) {
			suml += s[l] - '0';
			sumr += s[r] - '0';

			if (suml == sumr) {
				ans = max(ans, r - l + 1);
			}
			l--;
			r++;
		}
	}

	cout << ans;
}