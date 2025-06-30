#pragma once
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

int n;
unordered_set<int> v;

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.insert(num);
	}

	vector<int> v2(v.begin(), v.end());
	sort(v2.begin(), v2.end());

	for (auto i : v2) {
		cout << i << " ";
	}

}