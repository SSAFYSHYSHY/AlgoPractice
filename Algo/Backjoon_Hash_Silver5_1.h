#pragma once
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
	int n;
	char type;
	unordered_set<string> map;

	cin >> n >> type;

	int cnt = 0;
	if (type == 'Y') cnt = 2;
	else if (type == 'F') cnt = 3;
	else if (type == 'O') cnt = 4;

	for (int i = 0; i < n; i++) {
		string s2;
		cin >> s2;

		map.insert(s2);
	}

	int max_game = map.size() / (cnt - 1);
	cout << max_game;
}