#pragma once
#include <iostream>

using namespace std;

int arr[250001];
int ans, n, cnt = 1;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == cnt) {
			cnt++;
			continue;
		}
		ans++;
	}

	cout << ans;
}