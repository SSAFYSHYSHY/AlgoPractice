#pragma once
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int maxlen = 0;
	int ansl = 0, ansr = 0;

	int l = 0;
	for (int r = 0; r < n; r++) {

		if (r >= 2 && v[r] == v[r - 1] && v[r - 1] == v[r - 2]) {
			l = r - 1;
		}

		if (r - l + 1 > maxlen) {
			maxlen = r - l + 1;
			ansl = l;
			ansr = r;

		}

	}

	cout << ansl + 1 << " " << ansr + 1;
}