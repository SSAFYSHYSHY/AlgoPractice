#pragma once
#include <iostream>
#include <vector>

using namespace std;

int n, k;

int main() {
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int sum = 0;
	//k개의 합 연산.
	for (int i = 0; i < k; i++) {
		sum += v[i];
	}

	int max_sum = sum;

	for (int i = k; i < n; i++) {
		sum = sum - v[i - k] + v[i];

		if (sum > max_sum) {
			max_sum = sum;
		}
	}

	cout << max_sum;
}