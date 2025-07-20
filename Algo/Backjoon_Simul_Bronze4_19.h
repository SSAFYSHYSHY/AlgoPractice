#pragma once
#include <iostream>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;

	if (x > 7) cout << x - 7;
	else {
		cout << y + 7;
	}
}