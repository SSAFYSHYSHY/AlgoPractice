#pragma once
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int n, m, ans = 0;
unordered_set<string> set;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		set.insert(s);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (set.find(s) != set.end()) {
			ans++;
		}
	}

	cout << ans;

}