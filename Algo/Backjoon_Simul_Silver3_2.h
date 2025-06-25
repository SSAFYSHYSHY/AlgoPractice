#pragma once
#include <iostream>

using namespace std;

int a, b, c, d;

int gcd(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	cin >> a >> b >> c >> d;

	int n, m;
	n = (a * d + b * c);
	m = (b * d);

	int g = gcd(n, m);

	cout << n / g << " " << m / g;

}