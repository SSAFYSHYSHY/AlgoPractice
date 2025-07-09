#pragma once
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, cnt = 0;
	string s;
	cin >> n >> s;

	for (int i = 0; i < n - 1; i++) {
		if ((s[i] == 'O' && s[i + 1] == 'X') || (s[i] == 'X' && s[i + 1] == 'O')) {
			cnt++;
			i++;
		}
	}

	cout << cnt;
}