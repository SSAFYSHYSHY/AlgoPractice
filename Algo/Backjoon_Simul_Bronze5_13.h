#pragma once
#include <iostream>

using namespace std;

int a, b;

int main() {
	cin >> a >> b;

	if (a > b) {
		cout << "flight";
	}
	else {
		cout << "high speed rail";
	}
}