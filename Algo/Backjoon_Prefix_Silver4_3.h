#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();

	vector<int> prefix(n + 1, 0);
	vector<int> v;

	for (int i = 0; i < n - 1; i++) {
		if (s[i] == '(' && s[i + 1] == '(') {
			v.push_back(i);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		prefix[i + 1] = prefix[i];

		if (s[i] == ')' && s[i + 1] == ')') {
			prefix[i + 1]++;
		}
	}

	int ans = 0;
	for (int i : v) {
		ans += prefix[n - 1] - prefix[i + 1];
	}

	cout << ans;
}