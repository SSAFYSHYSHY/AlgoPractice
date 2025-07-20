#pragma once
#include <iostream>

using namespace std;

int main() {
	int a, b, c, d;

	cin >> a >> b >> c >> d;

	a = b - a;
	c = d - c;

	while (a != c) {
		if (a < c) a += b;
		else c += d;
	}

	cout << a;
}