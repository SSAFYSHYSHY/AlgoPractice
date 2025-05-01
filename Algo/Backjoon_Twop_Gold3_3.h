#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, arr[601];

int main() {
	int l, r, a, b, temp, ans = 21e8;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 3; j < n; j++) {
			l = i + 1;
			r = j - 1;
			a = arr[i] + arr[j];

			while (l < r) {
				b = arr[l] + arr[r];

				temp = abs(a - b);
				ans = min(temp, ans);

				if (ans == 0) {
					cout << ans;
					return 0;
				}

				if (a > b) l++;
				else r--;
			}
		}
	}

	cout << ans;
}