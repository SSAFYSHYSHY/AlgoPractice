#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[101];
int brr[101];
int sum = 0;
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += abs(arr[i] - brr[i]);
	}

	cout << sum / 2;
}