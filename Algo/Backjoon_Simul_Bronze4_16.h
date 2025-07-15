#pragma once
#include <iostream>
#include <string>

using namespace std;

int cnt = 0, cnt1 = 0;

char c[] = { 'a','e','i','o','u' };

int main() {

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'y') cnt1++;

		for (int j = 0; j < 5; j++) {
			if (s[i] == c[j]) {
				cnt++;
			}
		}
	}

	cout << cnt << " " << cnt + cnt1;

}