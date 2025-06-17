#pragma once
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int max_gain = 0;
	int start = v[0];

	for (int i = 1; i < n; i++) {
		if (v[i] > v[i - 1]) {
			max_gain = max(max_gain, v[i] - start);
		}
		else {
			start = v[i];
		}
	}

	cout << max_gain;
}