#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int m, h;
int n;

int main() {
	cin >> m >> h;
	cin >> n;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int c, b;
		cin >> c >> b;

		int milk = c * m;
		int honey = b * h;

		ans += max(milk, honey);
	}
	cout << ans;

}