#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int n, c;
vector<int> v;
unordered_map<int, int> map;
unordered_map<int, int> first_map;

bool cmp(int a, int b) {
	if (map[a] != map[b]) return map[a] > map[b];
	return first_map[a] < first_map[b];
}

int main() {
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.push_back(num);
		map[num]++;

		if (first_map.find(num) == first_map.end()) {
			first_map[num] = i;
		}
	}

	stable_sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}