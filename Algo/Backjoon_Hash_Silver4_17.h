#pragma once
#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
unordered_set<string> set;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		vector<char> v;
		for (int j = 0; j < s.length(); j++) {
			v.push_back(s[j]);
		}
		sort(v.begin(), v.end());

		string new_s;
		for (int j = 0; j < s.length(); j++) {
			new_s += v[j];
		}

		set.insert(new_s);
	}

	cout << set.size();
}