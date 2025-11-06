#pragma once
#include <iostream>
#include <cstring>

using namespace std;

int n, t;
int arr[100001];

int main() {
	cin >> t;

	while (t--) {
		memset(arr, 0, sizeof(arr));

		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		int curr = arr[1];
		int cnt = 1;

		while (curr != n && cnt <= n) {
			curr = arr[curr];
			cnt++;
		}

		cout << (cnt > n ? 0 : cnt) << "\n";
	}
}
