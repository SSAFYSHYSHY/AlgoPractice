#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int arr[50][6];
int ans[6];

int main() {
	for (int i = 0; i < 6; i++) {
		cin >> ans[i];
	}

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}

	int maxi = 0, cnt = 0;
	for (int i = 0; i < 50; i++) {
		cnt = 0;

		for (int j = 0; j < 6; j++) {
			if (arr[i][j] == ans[j]) {
				cnt++;
			}
		}

		maxi = max(maxi, cnt);
	}
	cout << maxi;
}