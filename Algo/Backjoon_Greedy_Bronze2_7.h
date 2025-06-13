#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	unordered_map<int, int> map;

	for (int i = 0; i < m; i++) {
		int k, s, e;
		cin >> k >> s >> e;

		if (map[k] <= s) {
			cout << "YES\n";
			map[k] = e;
		}
		else {
			cout << "NO\n";
		}
	}

}