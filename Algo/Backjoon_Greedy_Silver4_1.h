#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;


int main() {
	cin >> n >> m;

	int mini = 1001;
	int sini = 1001;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		mini = min(mini, a);
		sini = min(sini, b);
	}

	int cost1 = n * sini;
	int cost2 = ((n + 5) / 6) * mini;

	int full = n / 6;
	int remain = n % 6;
	int cost3 = full * mini + remain * sini;

	cout << min({ cost1, cost2, cost3 });
}