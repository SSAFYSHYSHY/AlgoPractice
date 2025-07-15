#pragma once
#include <iostream>
#include <string>

using namespace std;

string s;
int a = 0, b = 0;

int main() {
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'C') {
			a++;
		}
		else {
			b++;
		}
	}

	a /= 2;
	b /= 2;

	cout << a + b;
}
