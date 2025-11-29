#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int t;

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main() {
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		unordered_map<string, int> map;

		for (int i = 0; i < n; i++) {
			string s;
			int num;
			cin >> s >> num;

			map[s] += num;
		}

		vector<pair<string, int>> v;
		for (auto i : map) {
			v.push_back({ i.first, i.second });
		}

		sort(v.begin(), v.end(), cmp);
		cout << v.size() << "\n";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].first << " " << v[i].second << "\n";
		}
	}
}