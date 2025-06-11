#pragma once
#include <iostream>

using namespace std;

int n;

int main() {
	cin >> n;

	int a = n % 2 ? n - 1 : n;

	for (int i = 0; i < a; i++) {
		if (i % 2) {
			cout << "2 ";
		}
		else {
			cout << "1 ";
		}
	}


	if (n % 2) {
		cout << "3";
	}
}