#pragma once
#include <iostream>
#include <string>

using namespace std;

int n;

int main() {
	string s;
	cin >> n;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'I') {
			cout << "i";
		}
		else {
			cout << "L";
		}
	}
}