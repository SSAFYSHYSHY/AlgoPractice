#pragma once
#include <iostream>
#include <stack>

using namespace std;

int t;

int main() {
	cin >> t;

	while (t--) {
		stack<int> s;

		int x;
		cin >> x;

		while (x) {
			s.push(x % 3);
			x /= 3;
		}

		while (!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}

		cout << "\n";
	}
}