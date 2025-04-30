#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v, v1;
int n, m;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		v1.push_back(num);
	}

	sort(v.begin(), v.end(), greater<>());
	sort(v1.begin(), v1.end(), greater<>());

	int l = 0, r = 0;
	int cnt = 0;

	while (l < n && r < m) {
		if (v[l] > v1[r]) {
			cnt++;
			l++;
			r++;
		}
		else {
			r++;
		}
	}

	cout << n + cnt;
}