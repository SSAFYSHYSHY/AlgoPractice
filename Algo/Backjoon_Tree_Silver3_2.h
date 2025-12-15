#pragma once
#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;

	cout << (n - 1) + (n - 2) * (n - 1) << "\n";
	for (long long i = 2; i <= n; i++) {
		cout << "1 " << i << "\n";
	}
}