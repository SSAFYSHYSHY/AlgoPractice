#pragma once
#include <string>
#include <iostream>

using namespace std;

string s;

int main() {
	int n, m;
	cin >> n >> m;
	cin >> s;

	for (int i = 0; i < m; i++) {
		string x;
		cin >> x;
		bool flag = false;

		for (int j = 0, idx = 0; x[j]; j++) {
			if (x[j] == s[idx]) idx++;

			if (idx == n) {
				flag = true;
				break;
			}
		}

		if (flag)
			cout << "true\n";
		else
			cout << "false\n";
	}
}