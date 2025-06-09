#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <string>

using namespace std;

int main() {
	int k, l;
	cin >> k >> l;

	unordered_set<string> map;
	unordered_map<string, list<string>::iterator> map2;
	list<string> wait;

	for (int i = 0; i < l; i++) {
		string s;
		cin >> s;

		if (map.count(s)) {
			wait.erase(map2[s]);
		}
		else {
			map.insert(s);
		}

		wait.push_back(s);
		map2[s] = prev(wait.end());
	}

	int cnt = 0;
	for (const string& student : wait) {
		if (cnt++ == k) {
			break;
		}
		cout << student << "\n";
	}
}
