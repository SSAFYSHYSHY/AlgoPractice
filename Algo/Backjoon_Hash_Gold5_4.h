#pragma once
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<pair<int, int>, int> cnt;
int N, ans = 0, x, y;

int GCD(int num1, int num2) {
	while (num2 != 0) {
		int temp = num1 % num2;
		num1 = num2;
		num2 = temp;
	}

	return num1;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		int gcd = GCD(abs(x), abs(y));

		cnt[make_pair(x / gcd, y / gcd)]++;
	}

	for (auto c : cnt) {
		ans = ans < c.second ? c.second : ans;
	}

	cout << ans;

	return 0;
}