#pragma once
#include <iostream>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int sum = a + b + c + d;

	if (sum + 300 <= 1800) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

}