#pragma once
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	string tar = "KOREA";
	int idx = 0;
	int cnt = 0;

	for (char ch : s) {
		if (ch == tar[idx]) {
			idx++;
			cnt++;
			if (idx == 5) {
				idx = 0;
			}
		}
	}

	cout << cnt;
}