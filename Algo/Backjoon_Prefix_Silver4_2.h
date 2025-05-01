#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, k, ans = 0;
long long prefix[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	cin >> prefix[0];

	for (int i = 1; i < n; i++) {
		cin >> prefix[i];
		prefix[i] += prefix[i - 1];
	}

	sort(prefix, prefix + n, greater<long long>());

	for (long long i = 0; i < k; i++) {
		ans += prefix[i];
	}

	cout << ans;
}