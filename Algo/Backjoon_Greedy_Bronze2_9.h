#pragma once
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	long long m;

	cin >> n >> m;

	vector<long long> v(n);

	long long max_t = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		max_t += v[i] - 1;
	}

	if (max_t >= m) {
		cout << "DIMI";
	}
	else {
		cout << "OUT";
	}
}