#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	unordered_map<string, int> map;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		vector<string> v(3);

		cin >> v[0] >> v[1] >> v[2];
		sort(v.begin(), v.end());

		string key = v[0] + " " + v[1] + " " + v[2];
		map[key]++;

		ans = max(ans, map[key]);
	}

	cout << ans;
}