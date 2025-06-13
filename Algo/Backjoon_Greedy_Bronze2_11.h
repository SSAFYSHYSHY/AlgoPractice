#pragma once
#include <iostream>

using namespace std;

int n, a, b, c;
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> a >> b >> c;

	if (n > 1) {
		if (a < c || b < c) {
			ans = (n - 1) * min(a, b);
		}
		else {
			ans = min(a, b) + (n - 2) * c;
		}
	}

	cout << ans / 100 << " " << ans % 100;
}