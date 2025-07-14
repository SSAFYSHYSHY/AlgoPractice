#pragma once
#include <iostream>

using namespace std;

long long arr[200001];

int main() {
	long long sum = 0;

	long long n;
	cin >> n;

	for (long long i = 0; i < n; i++) {
		long long num;
		cin >> num;

		if (num == 0) {
			sum -= 1;
		}
		else {
			sum += 1;
		}

		arr[i] = sum;
	}

	long long ans = 0;
	for (long long i = 0; i < n; i++) {
		ans += arr[i];
	}

	cout << ans;

}