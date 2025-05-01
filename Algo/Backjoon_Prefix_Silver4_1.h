#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long arr[1001];
long long prefix[1001];
long long ans = 0;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		prefix[i] = prefix[i - 1] + abs(arr[i] - arr[i - 1]);
	}

	while (m--) {
		int l, r;
		cin >> l >> r;

		if ((r - 1) < l) {
			cout << 0 << "\n";
		}
		else {
			cout << prefix[r] - prefix[l] << "\n";
		}
	}

}