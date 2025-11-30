#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int n, m;
unordered_map<string, int> map;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		map[s] = i;
	}

	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;

		int x = map[a];
		int y = map[b];

		cout << abs(y - x) - 1 << "\n";
	}


}