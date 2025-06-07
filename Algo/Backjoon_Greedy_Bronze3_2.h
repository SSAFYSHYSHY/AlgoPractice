#pragma once
#include <iostream>

using namespace std;

int arr[5000001];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int i = 0;
	int ans = 0;
	while (i < n) {
		ans++;

		int j = i + 1;

		while (j < n && arr[j - 1] > arr[j]) {
			j++;
		}

		i = j;
	}

	cout << ans;
}