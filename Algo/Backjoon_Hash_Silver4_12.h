#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;

int n;
unordered_map<string, int> map;

int main() {
	cin >> n;

	for (int i = 0; i < (2 * n) - 1; i++) {
		string s;
		cin >> s;

		map[s]++;
	}

	for (auto i : map) {
		if (i.second % 2 == 1) {
			cout << i.first;
			break;
		}
	}

}