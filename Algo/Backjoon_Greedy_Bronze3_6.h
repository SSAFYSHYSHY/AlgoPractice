#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long arr[3], brr[3];

int main() {
	for (long long i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	for (long long i = 0; i < 3; i++) {
		cin >> brr[i];
	}

	sort(arr, arr + 3, greater<long long>());
	sort(brr, brr + 3, greater<long long>());

	long long sum = 0;
	for (long long i = 0; i < 3; i++) {
		sum += arr[i] * brr[i];
	}

	cout << sum;
}
