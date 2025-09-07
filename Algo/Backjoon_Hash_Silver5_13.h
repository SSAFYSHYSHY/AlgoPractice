#pragma once
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {

	while (1) {
		int n;
		cin >> n;

		if (n == 0) break;

		string s;
		unordered_set<char> set;
		cin >> s;

		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			//만약 존재하지 않을때.
			if (set.find(s[i]) == set.end()) {

				//수가 n 보다 많으면. cnt++
				if (set.size() >= n) {
					cnt++;
				}
				//수가 n 보다 적으면 넣기. 
				else {
					set.insert(s[i]);
				}
			}
			//똑같은 수 발견시.
			else {
				set.erase(s[i]);
			}
		}

		if (cnt == 0) {
			cout << "All customers tanned successfully.\n";
		}
		else {
			cout << cnt / 2 << " customer(s) walked away.\n";
		}
	}

}