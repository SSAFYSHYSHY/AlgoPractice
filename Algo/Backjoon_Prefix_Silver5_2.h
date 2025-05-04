#pragma once
"#include <iostream>
#include <algorithm>

using namespace std;

long long n;
long long arr[1001];
long long prefix[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long t;
	cin >> t;

	for (long long i = 0; i < t; i++) {
		long long n;
		cin >> n;

		long long sum = 0;
		for (long long j = 0; j < n; j++) {
			long long num;
			cin >> num;

			sum += num;
		}

		arr[i] = sum;
	}
	sort(arr, arr + t);

	long long sum = 0;
	for (long long i = 0; i < t; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
		sum += prefix[i];
	}

	cout << sum;
}"
