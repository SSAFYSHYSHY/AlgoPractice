#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, int> m;
int n, ans;
string str;

int main() {
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> str;
		m[str] = i;
	}

	for (int i = 0; i < n; i++) {
		cin >> str;
		v[i] = m[str];
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] < v[j]) {
				ans++;
			}
		}
	}

	cout << ans << "/" << (n * (n - 1) / 2);
}