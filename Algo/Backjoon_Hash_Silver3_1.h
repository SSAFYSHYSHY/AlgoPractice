#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		unordered_map<string, int> map;

		for (int i = 0; i < n; i++) {
			string name, type;
			cin >> name >> type;

			map[type]++;
		}

		int ans = 1;
		for (auto pair : map) {
			ans *= (pair.second + 1);
		}

		cout << ans - 1 << "\n";
	}
}