#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
unordered_map<string, int> map;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	return a.first < b.first;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		int idx = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '.') {
				idx = j;
			}
		}

		string temp;
		for (int j = idx + 1; j < s.length(); j++) {
			temp += s[j];
		}

		map[temp]++;
	}

	vector<pair<string, int>> v(map.begin(), map.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

}