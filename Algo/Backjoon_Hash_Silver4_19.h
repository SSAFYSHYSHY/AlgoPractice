#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;

int n;
unordered_map<string, int> map;

int main() {
	cin >> n;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		map[s]++;

		if (map.find(s) != map.end()) {
			if (map[s] >= 5) {
				ans = i;
				break;
			}
		}
	}

	if (ans > 0) {
		cout << ans + 1;
	}
	else {
		cout << 0;
	}

}