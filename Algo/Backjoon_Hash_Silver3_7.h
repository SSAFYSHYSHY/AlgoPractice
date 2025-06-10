#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, m;
unordered_map<string, vector<string>> map;
unordered_map<string, string> map2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		int num;

		cin >> s >> num;

		vector<string> members;

		for (int j = 0; j < num; j++) {
			string s2;
			cin >> s2;

			members.push_back(s2);
			map2[s2] = s;
		}

		map[s] = members;
	}

	for (int i = 0; i < m; i++) {
		string s;
		int q;

		cin >> s >> q;

		if (q == 0) {
			vector<string> v = map[s];
			sort(v.begin(), v.end());

			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << "\n";
			}
		}
		else {
			cout << map2[s] << "\n";
		}
	}
}