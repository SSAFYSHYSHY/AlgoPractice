#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main() {
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> prefix(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		prefix[i] = max(prefix[i + 1], v[i]);
	}

	for (int i = 0; i < n; i++) {
		int num = prefix[i + 1];
		int diff = max(0, num - v[i] + 1);

		cout << diff << " ";
	}
}