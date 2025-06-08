#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[500001];
set<int> map2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		map2.insert(num);
	}

	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (map2.find(arr[i]) == map2.end()) {
			v.push_back(arr[i]);
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (int x : v) cout << x << " ";
}
