#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int n;
unordered_map<string, vector<string>> map;
unordered_set<string> set;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;

		if (b == "-") continue;

		map[b].push_back(a);
	}

	int ans = 0;

	int cnt = 0;
	for (auto i : map) {
		string s = i.first;
		string new_s;

		if (map[s].size() == 2) {
			ans++;

			new_s = map[s][0] + " " + map[s][1];

			set.insert(new_s);
		}
	}

	cout << ans << "\n";
	if (ans != 0) {
		for (auto i : set) {
			cout << i << "\n";
		}

	}

}