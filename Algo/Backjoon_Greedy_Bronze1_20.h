#pragma once
#include <iostream>
#include< algorithm>

using namespace std;

int n;
int arr[16];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, greater<>());

	int a = 0, b = 0;
	for (int i = 0; i < n; i += 2) {
		a += arr[i];
		b += arr[i + 1];
	}

	cout << a << " " << b;
}