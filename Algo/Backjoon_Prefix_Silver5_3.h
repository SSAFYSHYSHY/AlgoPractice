#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1000001];
long long prefix[1000001];

int main() {
	long long n;
	cin >> n;

	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (long long i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + (arr[i - 1] == 0 ? 1 : 0);
	}

	long long sum = 0;
	for (long long i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			sum += prefix[i];
		}
	}

	cout << sum;
}