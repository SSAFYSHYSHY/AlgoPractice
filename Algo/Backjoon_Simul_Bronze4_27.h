#pragma once
#include <iostream>
#include <string>

using namespace std;

int main() {

	int a = 0, b = 0;
	for (int i = 0; i < 9; i++) {
		string s;
		cin >> s;

		if (s == "Lion") a++;
		else b++;
	}

	if (a > b) {
		cout << "Lion";
	}
	else {
		cout << "Tiger";
	}
}