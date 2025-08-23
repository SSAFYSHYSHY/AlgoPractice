#pragma once
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string s;

unordered_set<int> P, K, H, T;

int main() {
	cin >> s;

	for (int i = 0; i < s.length(); i += 3) {
		char c = s[i];
		int num = stoi(s.substr(i + 1, 2));

		if (c == 'P') {
			if (P.find(num) != P.end()) { cout << "GRESKA"; return 0; }
			P.insert(num);
		}
		if (c == 'K') {
			if (K.find(num) != K.end()) { cout << "GRESKA"; return 0; }
			K.insert(num);
		}
		if (c == 'H') {
			if (H.find(num) != H.end()) { cout << "GRESKA"; return 0; }
			H.insert(num);
		}
		if (c == 'T') {
			if (T.find(num) != T.end()) { cout << "GRESKA"; return 0; }
			T.insert(num);
		}
	}

	cout << 13 - (int)P.size() << " ";
	cout << 13 - (int)K.size() << " ";
	cout << 13 - (int)H.size() << " ";
	cout << 13 - (int)T.size() << "";

}