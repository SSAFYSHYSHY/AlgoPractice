#pragma once
#include <iostream>
using namespace std;

string arr[10][5] = {
	{"0000", "0  0", "0  0", "0  0", "0000"},
	{"   1", "   1", "   1", "   1", "   1"},
	{"2222", "   2", "2222", "2", "2222"},
	{"3333", "   3", "3333", "   3", "3333"},
	{"4  4", "4  4", "4444", "   4", "   4"},
	{"5555", "5", "5555", "   5", "5555"},
	{"6666", "6", "6666", "6  6", "6666"},
	{"7777", "   7", "   7", "   7", "   7"},
	{"8888", "8  8", "8888", "8  8", "8888"},
	{"9999", "9  9", "9999", "   9", "   9"}
};

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		int idx = s[i] - '0';
		for (int j = 0; j < 5; j++) {
			cout << arr[idx][j] << "\n";
		}
		if (i != s.length() - 1)
			cout << "\n";
	}
}