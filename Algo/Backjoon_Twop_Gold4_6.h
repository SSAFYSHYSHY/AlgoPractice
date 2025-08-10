#pragma once
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
char arr[2001];
string ans;

bool Calc(int l, int r) {
	while (l <= r) {
		if (arr[l] < arr[r]) return true;
		if (arr[l] > arr[r]) return false;
		l++;
		r--;
	}

	return true;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int l = 0, r = n - 1;

	while (l <= r) {
		if (Calc(l, r)) {
			ans += arr[l];
			l++;
		}
		else {
			ans += arr[r];
			r--;
		}
	}

	int cnt = 0;
	for (int i = 0; i < ans.length(); i++) {
		cout << ans[i];
		cnt++;

		if (cnt == 80) {
			cout << "\n";
			cnt = 0;
		}

	}
}