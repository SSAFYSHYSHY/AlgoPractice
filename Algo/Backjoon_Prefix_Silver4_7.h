#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100001];
long long prefix[100001];
int k, n;

int main() {
	cin >> k >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		prefix[i] = prefix[i - 1] + arr[i];
	}

	int ans = 0;
	bool flag = false;
	for (int i = 1; i <= 4; i++) {
		if (prefix[i] > k) {
			flag = true;
			break;
		}
		ans = i;
	}

	if (flag) {
		cout << ans;
		return 0;
	}

	for (int i = 5; i <= n; i++) {
		int num = prefix[i] - prefix[i - 4];

		if (num > k) {
			break;
		}
		ans = i;
	}

	cout << ans;

}