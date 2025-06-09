#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
unordered_map<string, int> map;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second) return a.second > b.second;
	if (a.first.length() != b.first.length()) return a.first.length() > b.first.length();
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s.length() >= m) {
			map[s]++;
		}
	}

	vector<pair<string, int>> v(map.begin(), map.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << "\n";
	}
}