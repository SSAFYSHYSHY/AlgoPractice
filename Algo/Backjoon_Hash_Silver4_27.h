#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int n;
unordered_map<string, int> map;
vector<pair<string, int>> v;

bool cmp(pair<string, int> a, pair<string, int > b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		map[s]++;
	}

	for (auto i : map) {
		v.push_back({ i.first, i.second });
	}
	sort(v.begin(), v.end(), cmp);

	cout << v[v.size() - 1].first << " " << v[v.size() - 1].second;
}