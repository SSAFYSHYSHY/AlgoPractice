#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, idx;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> idx;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		v.push_back(x);
	}
	sort(v.begin(), v.end());

	cout << v[idx - 1];
}