#pragma once
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> map;
int n, m;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		map.insert(s);
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (map.find(s) != map.end()) {
			ans++;
		}
	}
	cout << ans;
}


