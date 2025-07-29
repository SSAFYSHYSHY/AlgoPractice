#pragma once
#include <iostream>

using namespace std;

int n;
int cnt = 0;
int mx = 0, mn = 0;

int main() {
	cin >> n;

	while (n--) {
		int x;
		cin >> x;

		if (x == 1) cnt++;
		else {
			cnt--;
		}

		mx = max(mx, cnt);
		mn = min(mn, cnt);
	}

	cout << mx - mn;

}