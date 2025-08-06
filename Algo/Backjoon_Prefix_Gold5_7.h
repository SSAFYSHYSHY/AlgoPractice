#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long n;
long long prefix[50001];
long long arr[50001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	prefix[0] = arr[0];
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	long long maxi = 0;

	for (long long i = n - 1; i > 0; i--) {
		if (prefix[i] % 7 == 0) {
			maxi = max(maxi, i + 1);
		}
		for (long long j = i - 1; j >= 0; j--) {
			if ((prefix[i] - prefix[j]) % 7 == 0) {
				maxi = max(maxi, i - j);
			}
		}
	}
	cout << maxi;

}