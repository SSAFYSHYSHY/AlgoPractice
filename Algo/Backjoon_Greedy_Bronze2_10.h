#pragma once
#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

unordered_map<string, long long> map;

bool cmp(const pair<string, long long>& a, const pair<string, long long>& b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout << fixed;
	cout.precision(4);

	string s;

	while (getline(cin, s)) {
		if (s.empty()) continue;
		map[s]++;

	}

	vector<pair<string, long long>> v(map.begin(), map.end());
	sort(v.begin(), v.end(), cmp);

	long long len = 0;
	for (auto& p : map) len += p.second;

	for (long long i = 0; i < v.size(); i++) {
		string name = v[i].first;
		long long cnt = v[i].second;

		cout << name << " " << ((double)cnt / len * 100) << "\n";
	}
}
