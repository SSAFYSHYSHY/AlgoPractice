#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int n;
unordered_map<string, int> map;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		map[s]++;
	}

	string ans;
	int cnt = 0;

	for (auto& num : map) {
		if (num.second > cnt) {
			cnt = num.second;
			ans = num.first;
		}
		else if (num.second == cnt) {
			ans = min(ans, num.first);
		}
	}

	cout << ans;

}
