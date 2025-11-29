#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int n;
	cin >> n;

	unordered_map<long long, int> map;

	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;

		while (x % 2 == 0) x /= 2;

		map[x]++;
	}

	int ans = 0;
	for (auto& p : map) {
		ans = max(ans, p.second);
	}

	cout << ans;
}