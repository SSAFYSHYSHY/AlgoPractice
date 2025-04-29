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

	sort(v.begin(), v.end());

	int maj = n / 2 + 1;
	int min_range = 1e9;

	for (int i = 0; i <= n - maj; i++) {
		int range = v[i + maj - 1] - v[i];
		min_range = min(min_range, range);
	}

	cout << min_range;
}