#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<string, int> map;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		int price;

		cin >> s >> price;

		map.insert({ s, price });
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		string s;
		int price;

		cin >> s >> price;

		if (map.find(s) != map.end()) {
			int num = map[s];

			if (price > num * (1.05)) {
				ans++;
			}
		}
	}
	cout << ans;
}
