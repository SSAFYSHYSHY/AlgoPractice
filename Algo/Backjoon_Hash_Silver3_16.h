#pragma once
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	while (cin >> n) {
		unordered_set<string> map;

		for (int i = 0; i < n; i++) {
			bool visited[10] = { false };

			string s, str;
			cin >> s;

			//중복 제거.
			for (int j = 0; j < s.length(); j++) {
				if (!visited[s[j] - '0']) {
					visited[s[j] - '0'] = true;
					str += s[j];
				}
			}
			sort(str.begin(), str.end());

			//
			map.insert(str);
		}

		cout << map.size() << "\n";
	}

}