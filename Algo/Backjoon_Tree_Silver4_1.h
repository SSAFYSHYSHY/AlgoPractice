#pragma once
#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n - m; i++) {
		cout << i << " " << i + 1 << "\n";
	}

	for (int i = n - m; i < n - 1; i++) {
		cout << n - m << " " << i + 1 << "\n";
	}

}