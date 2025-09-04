#pragma once
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int n;
unordered_set<string> map;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		map.insert(s);
	}

	int m, cnt = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (map.find(s) != map.end()) {
			cnt++;
		}
	}

	cout << cnt;
}