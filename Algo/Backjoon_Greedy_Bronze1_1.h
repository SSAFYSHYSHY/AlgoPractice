#pragma once
#include <iostream>

using namespace std;

int main() {
	int l, p, v;
	int n = 1;

	while (1) {
		cin >> l >> p >> v;

		if (l == 0 && p == 0 && v == 0) break;

		int full = v / p;
		int reamin = v % p;

		int total = full * l + min(l, reamin);

		cout << "Case " << n << ": " << total << "\n";
		n++;
	}
}