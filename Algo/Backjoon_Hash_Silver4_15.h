#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int n;
	cin >> n;

	unordered_map<int, int >map;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		map[x] = y;
	}

	int r;
	cin >> r;

	for (int i = 0; i < r; i++) {
		int l;
		cin >> l;

		bool flag = true;
		int ans[101];

		for (int j = 0; j < l; j++) {
			int s;
			cin >> s;

			if (map.find(s) != map.end()) {
				ans[j] = map[s];
			}
			else {
				flag = false;
			}
		}

		if (!flag) {
			cout << "YOU DIED\n";
		}
		else {
			for (int j = 0; j < l; j++) {
				cout << ans[j];
				if (j < l - 1) cout << " ";
			}
			cout << "\n";
		}
	}
}