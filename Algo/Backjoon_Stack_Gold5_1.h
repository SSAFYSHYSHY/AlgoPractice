#pragma once
#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<pair<int, int>> s;
	int num, h;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> h;

		while (!s.empty()) {
			if (h < s.top().second) {
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}

		if (s.empty()) {
			cout << 0 << " ";
		}
		s.push({ i + 1, h });
	}
}