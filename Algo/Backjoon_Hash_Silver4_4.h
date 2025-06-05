#pragma once
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> a, b;
int n, m;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		a.insert(x);
	}

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;

		b.insert(x);
	}

	int cnt = 0;
	for (auto x : a) {
		if (b.find(x) == b.end()) {
			cnt++;
		}
	}

	for (auto x : b) {
		if (a.find(x) == a.end()) {
			cnt++;
		}
	}

	cout << cnt << "\n";
}