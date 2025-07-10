#pragma once
#include <iostream>

using namespace std;

int a, b, c;
int n;

int main() {
	cin >> a >> b >> c;

	cin >> n;

	if (a * n + b <= c * n && a <= c) {
		cout << 1;
	}
	else {
		cout << 0;
	}

}