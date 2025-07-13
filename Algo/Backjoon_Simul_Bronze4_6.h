#pragma once
#include <iostream>

using namespace std;

int n;

int main() {
	cin >> n;

	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i == n || j == n || i * j == n) {
				cout << 1;
				return 0;
			}
		}
	}

	cout << 0;

}