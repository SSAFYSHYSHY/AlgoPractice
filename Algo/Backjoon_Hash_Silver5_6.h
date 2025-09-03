#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
unordered_map<string, int> map;
vector<int> v;

int sum = 0, sum2 = 0;
int mini = 21e8;
int maxi = 0;

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		string s;
		int num;

		cin >> s >> num;

		map.insert({ s,num });
	}

	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;

		if (map.find(s) != map.end()) {
			sum += map[s];
			map.erase(s);
		}
	}

	sum2 = sum;

	for (auto i : map) {
		v.push_back(i.second);
	}

	sort(v.begin(), v.end());

	int need = m - k;
	for (int i = 0; i < need; i++) {
		sum += v[i];
	}

	for (int i = 0; i < need; i++) {
		sum2 += v[v.size() - 1 - i];
	}

	cout << sum << " " << sum2;
}