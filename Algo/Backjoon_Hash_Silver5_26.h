#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

unordered_map<string, bool> map;
unordered_set<string> set;

int n, m;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		set.insert(s);
		map[s] = false;
	}

	int ans = 0;
	int cnt = 0;
	bool flag = false;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;

		cin >> s;

		if (set.find(s) != set.end() && !map[s]) {
			cnt++;
			map[s] = true;
		}

		if (cnt >= (n + 1) / 2 && !flag) {
			ans = i;
			flag = true;
		}
	}

	cout << ans + 1;


}

