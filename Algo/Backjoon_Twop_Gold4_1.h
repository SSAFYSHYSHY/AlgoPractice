#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}
	sort(v.begin(), v.end());

	long long cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			long long sum = v[i] + v[j];

			int lower = lower_bound(v.begin() + j + 1, v.end(), -sum) - v.begin();
			int upper = upper_bound(v.begin() + j + 1, v.end(), -sum) - v.begin();

			cnt += (upper - lower);

		}
	}

	cout << cnt;
}