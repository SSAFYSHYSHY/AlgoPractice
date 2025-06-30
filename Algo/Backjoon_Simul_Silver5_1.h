#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		v.push_back(x);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}
