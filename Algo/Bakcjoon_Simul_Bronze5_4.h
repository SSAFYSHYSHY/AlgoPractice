#pragma once
#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if ((a + b + c) <= 21) {
		cout << "1";
	}
	else {
		cout << "0";
	}
}