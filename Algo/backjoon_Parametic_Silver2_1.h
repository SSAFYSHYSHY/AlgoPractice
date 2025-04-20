#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, k;
vector<long long> arr;

bool Calc(long long x) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > x)
			cnt += arr[i] - x;
	}
	return cnt <= k;
}

int main() {
	cin >> n >> k;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long l = 0;
	long long r = *max_element(arr.begin(), arr.end());
	long long answer = r;

	while (l <= r) {
		long long mid = (l + r) / 2;
		if (Calc(mid)) {
			answer = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << answer << '\n';
	return 0;
}
