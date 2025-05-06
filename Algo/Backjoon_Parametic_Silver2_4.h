#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n;

bool Calc(const vector<long long>& v, long long mid) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += v[i] / mid;

		if (cnt >= 4) return true;

	}

	return false;
}

int main() {
	cin >> n;
	vector<long long> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	long long l = 1;
	long long r = v[v.size() - 1];
	long long ans = 0;

	while (l <= r) {
		long long mid = (l + r) / 2;

		if (Calc(v, mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans * ans;
}