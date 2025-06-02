#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long ans = 0;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		ans += (n / i) * i;
	}

	cout << ans;
}