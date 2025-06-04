#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> map;
vector<string> v;
int n, m;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		map[s] = 1;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (map[s] == 1) {
			v.push_back(s);
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

}