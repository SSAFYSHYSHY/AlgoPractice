#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, string> map, map2;
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;

		map[a] = b;
	}

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;

		map2[a] = b;
	}

	vector<pair<string, string>> v;
	for (auto i : map) {
		string name = i.first;

		for (auto j : map2) {
			if (name == j.first) {
				v.push_back({ i.second, j.second });
			}
		}

	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

}