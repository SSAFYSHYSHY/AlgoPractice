#pragma once
#include <string>
#include <iostream>

using namespace std;

int t;

int main() {
	cin >> t;

	while (t--) {
		int num;

		cin >> num;

		int ans = 0;
		while (1) {
			num++;

			string s = to_string(num);
			bool flag = false;

			for (int i = 0; i < s.length(); i++) {
				if (s[i] == '0') {
					flag = true;
					break;
				}
			}

			if (!flag) {
				ans = num;
				break;
			}
		}

		cout << ans << "\n";
	}
}