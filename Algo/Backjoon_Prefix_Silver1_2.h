#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, t;
long long arr[200001];
long long prefix[200001];

void Input() {
	cin >> n >> t;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();

	prefix[0] = 0;
	for (long long i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	while (t--) {
		long long num;
		cin >> num;

		long long idx = upper_bound(prefix + 1, prefix + n + 1, num) - prefix - 1;

		cout << idx << "\n";
	}
}