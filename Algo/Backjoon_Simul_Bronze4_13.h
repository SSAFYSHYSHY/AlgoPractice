#pragma once
#include <iostream>

using namespace std;

int n;

int main() {
	cout << fixed;
	cout.precision(2);

	cin >> n;
	for (int i = 0; i < n; i++) {
		double a, b;
		cin >> a >> b;

		cout << "The height of the triangle is " << (2 * a) / b << " units\n";
	}

}