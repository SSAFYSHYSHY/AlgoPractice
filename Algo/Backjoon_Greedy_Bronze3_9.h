#pragma once
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
		}
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;

		}

		if (n <= m) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
}