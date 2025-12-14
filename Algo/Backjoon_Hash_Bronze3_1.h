#pragma once
#include <iostream>
#include <string>
#include <set>

using namespace std;

int n;
set<string> arr;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		arr.insert(s);
	}

	string ans;
	for (int i = 0; i < n - 1; i++) {
		string s;
		cin >> s;

		if (arr.find(s) != arr.end()) {
			arr.erase(s);
		}
	}

	for (auto i : arr) {
		cout << i;
	}

}