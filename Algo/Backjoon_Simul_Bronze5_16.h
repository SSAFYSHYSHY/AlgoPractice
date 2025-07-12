#pragma once
#include <iostream>

using namespace std;

int n, cnt = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num % 2 != 0) {
			cnt++;
		}
	}

	cout << cnt;
}