#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long prefix[100001];
long long arr[100001];
int n, b, a;

int main() {
	cin >> n >> b >> a;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + n + 1);

	for (int i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	for (int i = 1; i <= n; i++) {
		int num;

		if (i >= a) {
			num = prefix[i - a] + (prefix[i] - prefix[i - a]) / 2;
		}
		else {
			num = prefix[i] / 2;
		}

		if (num > b) {
			cout << i - 1;
			return 0;
		}
	}

	cout << n;
}