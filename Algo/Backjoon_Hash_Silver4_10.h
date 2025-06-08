#pragma once
#include <iostream>
#include <map>

using namespace std;

int n, cnt = 0;

int main() {
	cin >> n;

	map<string, bool> m;
	string s, s1;

	while (n--) {
		cin >> s >> s1;

		if (s == "ChongChong") {
			m.insert({ s, true });
		}
		else if (s1 == "ChongChong") {
			m.insert({ s1, true });
		}

		if (m[s]) {
			m[s1] = true;
		}
		if (m[s1]) {
			m[s] = true;
		}
	}

	for (auto& num : m) {
		if (num.second) {
			cnt++;
		}
	}

	cout << cnt;
}