#pragma once
#include <iostream>
using namespace std;

int n, m;
int arr[1000001];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum >= m) {
			cout << i + 1 << '\n';
			return 0;
		}
	}

	cout << -1 << '\n';
	return 0;
}
