#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int n, k;
unordered_map<string, int> map;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		map[s]++;
	}

	string ans;
	for (auto i : map) {
		if (i.second % k != 0) {
			ans = i.first;
		}
	}

	cout << ans;
}