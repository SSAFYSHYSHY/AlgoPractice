#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<string, string> map;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;

		map[a] = b;
	}

	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;

		if (map.find(a) != map.end()) {
			cout << map[a] << "\n";
		}
	}
}
