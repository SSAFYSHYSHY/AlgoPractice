#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[50001];
int sum = 0, ans = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	int a = 0;
	int b = 1;
	int sa = arr[0];
	int sb = sum - arr[0];

	while (a < n) {
		ans = max(ans, min(sa, sb));

		if (sa >= sb) {
			sa -= arr[a];
			sb += arr[a];
			a++;
			continue;

		}

		sa += arr[b];
		sb -= arr[b];
		b++;
		b %= n;
	}

	cout << ans;
}