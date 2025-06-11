#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n);
		unordered_set<int> map;

		for (int i = 0; i < n; i++) {
			cin >> v[i];
			map.insert(v[i]);
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int a = v[i];
				int b = v[j];

				if ((a + b) % 2 != 0) continue;

				int c = (a + b) / 2;
				if (map.count(c)) {
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}
}