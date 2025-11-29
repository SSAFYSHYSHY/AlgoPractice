#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
unordered_map<string, int> map;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.first < b.first;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string a;
		int num;

		cin >> a >> num;

		map[a] += num;
	}

	vector<pair<string, int>> v;
	for (auto& i : map) {
		v.push_back({ i.first, i.second });
	}

	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}