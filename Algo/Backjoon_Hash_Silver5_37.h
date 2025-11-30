#pragma once
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int n, m;
unordered_set<string> set;

int main() {
	cin >> n >> m;

	string s;
	cin >> s;

	for (int i = 0; i <= s.length() - n; i++) {
		string new_s;

		for (int j = i; j < i + n; j++) {
			new_s += s[j];
		}

		set.insert(new_s);
	}

	cout << set.size();

}