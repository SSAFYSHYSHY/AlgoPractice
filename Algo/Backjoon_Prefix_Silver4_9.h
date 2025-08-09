#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long arr[200001];
long long prefix[200001];
long long n, ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	prefix[0] = 0;
	for (long long i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	int ans_idx = 0;
	for (long long i = 1; i < n; i++) {
		long long left = prefix[i];
		long long right = prefix[n] - prefix[i];
		long long mul = left * right;

		if (mul > ans) {
			ans = mul;
			ans_idx = i;
		}

	}
	cout << ans_idx;

}