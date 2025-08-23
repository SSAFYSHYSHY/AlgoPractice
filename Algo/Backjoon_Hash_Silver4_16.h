#pragma once
#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<pair<int, int>> arr;
vector<int> v;

int main() {
	int num;

	while (cin >> num) {
		v.emplace_back(num);
	}
	int len = v.size() - 1;

	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (v[i] + v[j] == v[len]) {
				if (v[i] < v[j]) {
					arr.insert(make_pair(v[i], v[j]));
				}
				else {
					arr.insert(make_pair(v[j], v[i]));
				}
			}
		}
	}

	for (auto& i : arr) {
		cout << i.first << " " << i.second << "\n";
	}
	cout << arr.size();
}