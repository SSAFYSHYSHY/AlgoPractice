#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long n;
unordered_map<long long, long long> map;
long long ans = 0;

int main() {
	cin >> n;

	for (long long i = 0; i < n; i++) {
		long long a;
		cin >> a;

		map[a]++;
	}

	long long ans = 0;
	long long cnt = 0;

	for (auto& num : map) {
		if (num.second > cnt) {
			cnt = num.second;
			ans = num.first;
		}
		else if (num.second == cnt) {
			ans = min(ans, num.first);
		}

	}

	cout << ans;
}