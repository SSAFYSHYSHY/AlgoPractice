#pragma once
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
unordered_set<string> map;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		map.insert(s);
	}


	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		string temp = "";
		for (int j = 0; j < s.length(); j++) {
			if (s[j] != ',') {
				temp += s[j];
			}
			else {
				map.erase(temp);
				temp = "";
			}
		}

		if (!temp.empty()) {
			map.erase(temp);
		}

		cout << map.size() << "\n";

	}

}