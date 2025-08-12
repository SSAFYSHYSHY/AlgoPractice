#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ans = 0;
vector<int> v, v2;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v2.push_back(v[i] + v[j]);
		}
	}
	sort(v2.begin(), v2.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (binary_search(v2.begin(), v2.end(), v[j] - v[i])) {
				ans = max(ans, v[j]);
			}
		}
	}
	cout << ans;

}