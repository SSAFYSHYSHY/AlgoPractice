#pragma once
#include <iostream>
#include <string>

using namespace std;

int main() {
	int a = 0, b = 0, n;
	string s;

	cin >> n;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '2') {
			a++;
		}
		else {
			b++;
		}
	}

	if (a > b) {
		cout << 2;
	}
	else if (a < b) {
		cout << "e";
	}
	else {
		cout << "yee";
	}

}
