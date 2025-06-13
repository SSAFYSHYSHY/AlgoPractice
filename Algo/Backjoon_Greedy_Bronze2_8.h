#pragma once
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	for (int i = 0; i < m; i++) {
		if (b[i] == 0) continue;
		sum *= b[i];
	}

	cout << sum;
}