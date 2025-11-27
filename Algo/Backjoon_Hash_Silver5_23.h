#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int n;
unordered_map<string, int> map;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		map[s]++;
	}

	int maxi = 0;
	for (auto& p : map) {
		if (p.second > maxi) {
			maxi = p.second;
		}
	}

	vector<string> ans;
	for (auto& p : map) {
		if (p.second == maxi) {
			ans.push_back(p.first);
		}
	}
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}