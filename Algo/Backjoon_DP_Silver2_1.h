#pragma once
#include <iostream>

using namespace std;

int arr[21][21][21];

int Calc(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return Calc(20, 20, 20);

	if (arr[a][b][c]) return arr[a][b][c];
	if (a < b && b < c) {
		arr[a][b][c] = Calc(a, b, c - 1) + Calc(a, b - 1, c - 1) - Calc(a, b - 1, c);
		return arr[a][b][c];
	}

	arr[a][b][c] = Calc(a - 1, b, c) + Calc(a - 1, b - 1, c) + Calc(a - 1, b, c - 1) - Calc(a - 1, b - 1, c - 1);
	return arr[a][b][c];
}

int main() {
	int a, b, c;

	while (1) {
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1) break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << Calc(a, b, c) << "\n";
	}
}
