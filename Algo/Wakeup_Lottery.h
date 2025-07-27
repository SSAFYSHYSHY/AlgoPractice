#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int arr[100][6] = {
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},

	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
};

int ans[6];

int main() {
	for (int i = 0; i < 6; i++) {
		cin >> ans[i];
	}

	int maxi = 0, cnt = 0;
	for (int i = 0; i < 100; i++) {
		cnt = 0;

		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				if (arr[i][j] == ans[k]) {
					cnt++;
				}

				if (cnt == 4) {
					cout << i << "\n";
				}
				if (cnt == 5) {
					cout << i << "\n";
				}
				if (cnt == 6) {
					cout << i << "\n";
				}
			}
		}

		maxi = max(maxi, cnt);
	}
	cout << maxi;
}