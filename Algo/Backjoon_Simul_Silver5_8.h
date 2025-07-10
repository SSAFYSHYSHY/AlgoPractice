#pragma once
#include <iostream>

using namespace std;

int main() {
	long long n, cnt = 0;
	cin >> n;

	for (int i = 1; i * i <= n; i++) {
		cnt++;
	}

	cout << cnt;
}