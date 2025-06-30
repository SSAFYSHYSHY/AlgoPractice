#pragma once
#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
unordered_map<int, int> map;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		map[num]++;
	}

	vector<int> v;
	for (auto i : map) {
		v.push_back(i.first);
	}
	sort(v.begin(), v.end());

	for (int i : v) {
		for (int j = 0; j < map[i]; j++) {
			cout << i << "\n";
		}
	}

}