#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, l, w, h;


int main() {
	cout.precision(10);
	cout << fixed;

	cin >> n >> l >> w >> h;

	double left = 0, right = 1000000000, mid;

	for (int i = 0; i < 10000; i++) {
		mid = (left + right) / 2;

		if (((long long)(l / mid) * (long long)(w / mid) * (long long)(h / mid)) < n) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	cout << left;
}