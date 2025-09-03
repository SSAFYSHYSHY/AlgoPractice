#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;

int t;
unordered_map<string, int> map;

int main() {
	cin >> t;

	while (t--) {
		int num;
		cin >> num;

		for (int i = 0; i < num; i++) {
			string s;
			cin >> s;

			map[s]++;
		}

		cout << map.size() << "\n";
		map.clear();
	}
}