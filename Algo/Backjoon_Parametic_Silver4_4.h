#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, ans;
bool visited[100001] = { false, };
int arr[100001] = { 0, };

bool Calc(int h) {

	for (int i = 0; i < m; i++) {
		if (i == 0) {
			if (arr[i] - h > 0) return false;
		}

		if (arr[i] - h > arr[i - 1] + h) return false;

		if (i == m - 1) {
			if (arr[i] + h < n) return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	ans = n;
	int l = 1, r = 100000;
	while (l <= r) {
		int mid = (l + r) / 2;

		if (Calc(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans;

}
