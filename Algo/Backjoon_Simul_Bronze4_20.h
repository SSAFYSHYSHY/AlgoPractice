#pragma once
#include <iostream>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a * b > c * d) {
		cout << "M";
	}
	else if (a * b < c * d) {
		cout << "P";
	}
	else {
		cout << "E";
	}
}