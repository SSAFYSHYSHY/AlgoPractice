#pragma once
#include <iostream>

using namespace std;

int t, x;

int main() {
	cin >> t >> x;

	int num, cnt = 0;
	cin >> num;
	bool flag = false;

	for (int i = 0; i < num; i++) {
		int a;
		cin >> a;

		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;

			if (b == x) flag = true;
		}

		if (!flag) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";

}