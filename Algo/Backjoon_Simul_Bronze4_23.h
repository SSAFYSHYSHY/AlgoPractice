#pragma once
#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int sum = a * 50 - b * 10;

	if (a > b) {
		sum += 500;
	}

	cout << sum;
}