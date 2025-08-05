#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> v;

long long maxi = 0, curr = 0;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int l = 0, r = n - 2;

	long long maxi = v[n - 1];
	int cnt = 1;

	if (k <= 2) {
		cout << maxi << "\n";
		return 0;
	}

	while (l < r) {
		cnt++;
		if (cnt == k)break;

		maxi += (v[r] - v[l]);
		cnt++;
		if (cnt == k) break;

		l++;
		r--;
	}

	cout << maxi;
}
