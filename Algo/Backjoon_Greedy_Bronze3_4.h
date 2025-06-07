#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long sum = 0;
long long arr[1000001];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++) {
		sum += (abs(arr[i] - arr[i + 1])) * (abs(arr[i] - arr[i + 1]));
	}

	cout << sum;
}