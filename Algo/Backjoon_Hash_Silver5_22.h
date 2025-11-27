#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> a, b;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		a[s]++;
	}

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		b[s]++;
	}

	long long ans = 0;
	for (auto& p : a) {
		const string& result = p.first;
		int a_cnt = p.second;
		int b_cnt = b[result];

		ans += min(a_cnt, b_cnt);
	}
	cout << ans;

}