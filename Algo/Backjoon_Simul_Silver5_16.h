#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	int arr[101];
	int t;
	cin >> t;

	int cnt = 1;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		int num;
		cin >> num;

		for (int i = 0; i < num; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + num);
		int gap = 0;
		for (int i = 0; i < num - 1; i++) {
			gap = max(gap, arr[i + 1] - arr[i]);
		}

		cout << "Class " << cnt << "\n";
		cout << "Max " << arr[num - 1] << ", Min " << arr[0] << ", Largest gap " << gap << "\n";
		cnt++;
	}

}