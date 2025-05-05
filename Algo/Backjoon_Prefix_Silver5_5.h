#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long arr[1000001];
long long prefix[1000001];
long long prefix2[1000001];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		prefix[i] = prefix[i - 1] + (arr[i] * arr[i]);
		prefix2[i] = prefix2[i - 1] + arr[i];
	}

	long long ans = 0;
	for (int k = 1; k < n; k++) {
		long long l = prefix[k];
		long long r = prefix2[n] - prefix2[k];

		ans = max(ans, l * r);
	}

	cout << ans;

}