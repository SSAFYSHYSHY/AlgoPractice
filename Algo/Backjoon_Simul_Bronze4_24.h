#pragma once
#include <iostream>

using namespace std;

int t;

int main() {
	cin >> t;

	cout << fixed;
	cout.precision(2);

	while (t--) {
		int num;
		cin >> num;
		double sum = 0;

		for (int i = 0; i < num; i++) {
			string s;
			int a;
			double b;

			cin >> s >> a >> b;

			sum += (a * b);
		}

		cout << "$" << sum << "\n";
	}
}