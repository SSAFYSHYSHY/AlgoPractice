#pragma once
#include <iostream>

using namespace std;

int n, x, y;
int ans = 4;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x >> y;
	if (x == 1)
		ans--;

	if (x == n)
		ans--;

	if (y == 1)
		ans--;

	if (y == n)
		ans--;

	cout << ans;
}