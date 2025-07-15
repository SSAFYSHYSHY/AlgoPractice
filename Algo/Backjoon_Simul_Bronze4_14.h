#pragma once
#include <iostream>

using namespace std;


int mod, num;

int main() {
	int a, b;
	cin >> a >> b;

	if (a > b) {
		num = b;
		mod = a - b;
	}
	else {
		num = a;
		mod = b - a;
	}

	for (int i = 0; i < mod; i++) {
		cout << "1";
	}
	for (int i = 0; i < num; i++) {
		cout << "2";
	}

}