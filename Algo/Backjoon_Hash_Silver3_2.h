#pragma once
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> map;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		string temp = "";

		for (int j = i; j < s.length(); j++) {
			temp += s[j];
			map.insert(temp);
		}
	}

	cout << map.size();
}