#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}

	int total = 0;
	int curr = 1;

	for (int i = 0; i < m; i++) {
		int tarr = v[i];

		int forward = (tarr - curr + n) % n;
		int back = (curr - tarr + n) % n;

		total += min(forward, back);
		curr = tarr;
	}
	cout << total;
}