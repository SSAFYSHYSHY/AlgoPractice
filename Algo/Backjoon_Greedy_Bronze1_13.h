#pragma once
#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;

	string s1 = "KOREA";
	string s2 = "YONSEI";

	int k1 = 0, k2 = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == s1[k1]) {
			k1++;
		}
		if (s[i] == s2[k2]) {
			k2++;
		}

		if (k1 == s1.length()) {
			cout << s1;
			return 0;
		}
		if (k2 == s2.length()) {
			cout << s2;
			return 0;
		}

	}
}