#pragma once
#include <iostream>
#include <vector>

using namespace std;

int n, k;
long long ans = 0;

int main() {
	cin >> n;


	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> k;

	int left = 0, right = 0;
	long long sum = 0;

	while (right < n) {
		sum += v[right];

		while (sum > k) {
			ans += n - right;
			sum -= v[left];
			left++;
		}

		right++;
	}

	cout << ans;
}