#pragma once
#include <iostream>

using namespace std;

int n, m;
int arr[101];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] >= arr[i + 1]) {
			int temp = arr[i + 1] - 1;
			if (temp < 0) {
				temp = 0;
			}

			ans += (arr[i] - temp);
			arr[i] = temp;
		}
	}
	cout << ans;
}