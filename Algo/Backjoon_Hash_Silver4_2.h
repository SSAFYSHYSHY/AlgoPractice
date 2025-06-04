#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
unordered_map<string, int> map;
unordered_map<int, string> map2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;

		map[s] = i;
		map2[i] = s;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if ('0' <= s[0] && s[0] <= '9') {
			int num = stoi(s);

			//해당 번호의 string 출력.
			cout << map2[num] << "\n";
		}
		else {
			//해당 글자의 번호 출력.
			cout << map[s] << "\n";
		}
	}
}