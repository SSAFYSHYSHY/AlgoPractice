#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, int> map;
vector<string> v;

int main() {

	while (1) {
		string s;
		cin >> s;

		if (s == "000-00-0000") break;

		map[s]++;
	}

	for (auto i : map) {
		if (i.second > 1) {
			v.push_back(i.first);
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

}