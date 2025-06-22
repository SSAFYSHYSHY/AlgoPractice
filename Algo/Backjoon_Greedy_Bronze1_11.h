#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, num = 1;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		num *= i;
	}

	cout << num;
}