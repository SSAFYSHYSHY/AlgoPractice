#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char arr[101][101];
int n;
int x = 0, y = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
		}
	}

	//가로
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '.') {
				cnt++;
			}
			else {
				if (cnt >= 2) x++;
				cnt = 0;
			}
		}

		if (cnt >= 2) x++;
	}

	//세로
	for (int j = 0; j < n; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == '.') {
				cnt++;
			}
			else {
				if (cnt >= 2) y++;
				cnt = 0;
			}
		}

		if (cnt >= 2) y++;
	}

	cout << x << " " << y;
}