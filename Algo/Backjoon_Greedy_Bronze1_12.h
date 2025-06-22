#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int ans = 1;

int main() {
	cin >> s;

	for (int i = 1; i < s.length(); i++) {
		if (s[i] <= s[i - 1]) {
			ans += 1;
		}
		else {
			continue;
		}
	}

	cout << ans;
}